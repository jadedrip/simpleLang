#include "stdafx.h"
#include <iostream>
#include "ClassContext.h"
#include "AstDef.h"
#include "AstClass.h"
#include "AstFunction.h"
#include "AstProtected.h"
#include "AstDef.h"
#include "AstCall.h"
#include "AstConst.h"
#include "AstGetClass.h"
#include "../Type/AutoType.h"
#include "../Type/ClassInstanceType.h"
#include "CodeGenerate/NewGen.h"
#include "CodeGenerate/DefGen.h"
#include "CodeGenerate/ThisGen.h"
#include "modules.h"
#include "utility.h"

using namespace std;
using namespace llvm;

CodeGen * AstClass::makeGen(AstContext * parent)
{
	parent->setClass(name, this);
	_context = parent;

	_templated = !templateVariables.empty();

	// 通过注解确定结构名
	for (auto a : annotations) {
		if (a.second->name == "CLang") {
			if (a.second->defaultValue)
				cStructName = a.second->defaultValue->name;
			else {
				static string name("name");
				auto *p=getMapValue(a.second->attrs, name);
				if (p) cStructName = p->name;
			}
		}
	}

	bool isProctected = false;
	for (auto i : block) {
		// 检测构造函数
		auto *p=dynamic_cast<AstFunction*>(i);
		if (p) {
			p->isProctected = isProctected;
			p->_cls = this;
			if (p->name == "Init") {
				if (!_construstor.empty())
					p->overload = true;
				_construstor.push_back(p);
			} else {
				_memberFunctions.push_back(p);
			}
			continue;
		} 

		// 检测是否模版类
		auto *q = dynamic_cast<AstDef*>(i);
		if (q) {
			for (auto i : q->vars) {
				Member m = { i.first, q->type, i.second };
				_members.push_back(m);
				if (!q->type || q->type->isAuto()) {
					assert(!q->vars.empty());
					if (!i.second) {	// 如果没有默认值
						_templated = true;
						templateVariables.push_back(i.first);
					}
				}
			}
		}				

		// 是否常量
		auto *e = dynamic_cast<AstConst*>(i);
		if (e) {
			constValues[i->name] = i->makeGen(parent);
		}

		auto y = dynamic_cast<AstProtected*>(i);
		if (y) {
			isProctected = true;
			continue;
		}
	}

	// 如果是非模板类，立刻生成实现
	if (!_templated) {
		ThisGen *gen = new ThisGen();
		std::map<std::string, AstType*> emptys;
		auto *p = generateClass(parent->context(), std::move(emptys));
		if (p->_type) {
			parent->setCompiledClass(p->_type->getStructName(), p);
			gen->type = p->_type;
		}
	}

	return nullptr;
}

CodeGen * AstClass::makeNew(AstContext* parent, 
	std::vector<std::pair<std::string, CodeGen*>>& args,
	std::vector<AstType*>* templateTypes
)
{						  
	llvm::LLVMContext &c = parent->context();
	NewGen* classObject = new NewGen();		// TODO: malloc
	//llvm::raw_os_ostream os(std::clog);
	//std::clog << "make New: ";

	std::map<std::string, AstType*> mappedTemplateTypes = createMappedTemplateTypes(templateTypes);

	ClassInstanceType* cls = nullptr;
	if (!_construstor.empty()) {
		AstFunction::OrderedParameters *ordered = nullptr;
		AstFunction *f = nullptr;
		for (auto x : _construstor) {
			x->genDefaultValue(_context);
			ordered = x->orderParameters(parent, args, &mappedTemplateTypes, true);
			if (ordered) {
				f = x;
				break;
			}
		}

		// 再进行不严格的匹配
		if(!ordered) for (auto x : _construstor) {
			ordered = x->orderParameters(parent, args, &mappedTemplateTypes);
			if (ordered) {
				f = x;
				break;
			}
		}
		if (f) {
			// 推导类
			cls = generateClass(c, mappedTemplateTypes); // 生成类（注意，这时部分方法可能还是模板的
			classObject->type = cls->_type;

			f->_parent = parent; // TODO: 不确定

			// 创建构造函数，并设置所有模板变量
			CodeGen* call = f->makeCall(
				parent,
				ordered->parameters,
				classObject,
				cls,
				&mappedTemplateTypes
			);

			if (!call)
				std::clog << "ERROR" << std::endl;
			classObject->construstor = call;
		}
		if (!cls) return nullptr;
	} else if (args.empty()) {
		cls = generateClass(c, std::move(mappedTemplateTypes));
		classObject->type = cls->_type;
	}

	if(!cls)
		throw std::runtime_error("类" + name + "没有合适的构造函数");

	classObject->defaultValues = cls->defaultValues;

	Type *type = classObject->type = cls->llvmType(c);
	//type->print(os);
	//os.flush();
	//std::clog << std::endl;
	//classObject->type = type;
	parent->setCompiledClass(type->getStructName(), cls);
	return classObject;
}

/**
* 本函数在 AstClass 类被转换为 ClassInstanceType 时被调用
*/
int AstClass::scanClass(ClassInstanceType* cls, AstContext* context, CodeGen* thisGen, std::vector< Type* >& types)
{
	bool isProctected = false;
	int idx = 0;
	auto &c=context->context();

	for (auto i : block) {
		// 创建函数、变量索引

		auto v = dynamic_cast<AstDef*>(i);
		if (v) {
			// String v="1", b
			for (auto a : v->vars) {
				ClassMemberGen* m = new ClassMemberGen();
				m->object = thisGen;
				m->name = a.first;
				m->isProtected = isProctected;
				// 如果是非模板变量，确定类型
				if (v->type->isAuto()) {
					if (!a.second) {
						auto u = dynamic_cast<AstGetClass*>(v->type);
						auto *l = context->findType(u ? u->name : a.first);
						if (!l)
							throw std::runtime_error("成员变量" + a.first + "无法确定类型");
						m->type = l->llvmType(c);
						cls->name += "_" + toReadable(m->type);
					}
				} else {
					auto *l = context->findType(v->type->name);
					if (l)
						m->type = l->llvmType(c);
					else
						m->type = v->type->llvmType(c);
				}
				m->index = idx++;
				cls->memberGens[a.first] = m;
				if (a.second) {
					auto *x=dynamic_cast<AstFunction*>(a.second);
					auto *g=cls->defaultValues[m->index] = a.second->makeGen(context);
					if (v->type->isAuto())
						m->type = g->type;
				} 
				context->setSymbolValue(a.first, m);
				types.push_back(m->type);
			}
			continue;
		}

		// throw std::runtime_error("类内有未知的定义");
	}

	for (auto i : constValues) {
		context->setSymbolValue(i.first, i.second);
	}
	return idx;
}

ClassInstanceType * AstClass::generateClass(AstContext* context, std::vector<AstType*>& templateTypes)
{
	string n = cStructName;
	
	if (!cStructName.empty()) {
		auto *p=context->findCompiledClass(n);
		if (p) return p;
		
		auto *c=CLangModule::getStruct(n);
		if (c) {
			auto *a = new ClassInstanceType(_context->pathName, n);
			a->_type = c;
			context->setCompiledClass(n, a);
			return a;
		}
	}
	return nullptr;
}


// 创建模板变量表

std::map<std::string, AstType*> AstClass::createMappedTemplateTypes(std::vector<AstType*>* templateTypes)
{
	std::map<std::string, AstType*> mappedTemplateTypes;
	if (templateTypes) {
		auto iter = templateVariables.begin();
		for (auto *i : *templateTypes) {
			if (iter == templateVariables.end()) {
				throw std::runtime_error("类" + name + "模板参数过多");
			}
			std::string &o = *iter;
			mappedTemplateTypes[o] = i;
			iter++;
		}
	}
	return mappedTemplateTypes;
}

void AstClass::fillMemberFunctionsTo(AstContext* context, ClassInstanceType * cls)
{
	for( auto x : _memberFunctions ){
		// 函数在被调用时才固化
		auto p = isTemplated() ? x->clone() : x;

		p->makeGen(context);
		//->_parent = context;
		auto it = cls->methds.find(p->name);
		if (it != cls->methds.end()) {
			it->second->overload = true;
			p->overload = true;
		}

		cls->methds.insert(std::make_pair(p->name, p));
	}
}

std::vector<llvm::Type*> AstClass::fillMember(AstContext *context, CodeGen* thisGen, ClassInstanceType * cls)
{
	int idx = 0;
	auto &c = context->context();
	std::vector<llvm::Type*> types;
	// String v="1", b
	for (auto a : _members) {
		AstType* v = a.type;

		ClassMemberGen* m = new ClassMemberGen();
		m->object = thisGen;
		m->name = a.name;
		// m->isProtected = isProctected;
		// 如果是非模板变量，确定类型
		if (v->isAuto()) {
			if (!a.defaultValue) {
				auto u = dynamic_cast<AstGetClass*>(v);
				auto *l = context->findType(u ? u->name : a.name);
				if (!l)
					throw std::runtime_error("成员变量" + a.name + "无法确定类型");
				m->type = l->llvmType(c);
				cls->name += "_" + toReadable(m->type);
			}
		} else {
			auto *l = context->findType(v->name);
			if (l)
				m->type = l->llvmType(c);
			else
				m->type = v->llvmType(c);
		}
		m->index = idx++;
		cls->memberGens[a.name] = m;
		if (a.defaultValue) {
			// auto *x = dynamic_cast<AstFunction*>(a.defaultValue);
			auto *g = cls->defaultValues[m->index] = a.defaultValue->makeGen(context);
			if (v->isAuto())
				m->type = g->type;
		}
		context->setSymbolValue(a.name, m);
		types.push_back(m->type);
	}
	return types;
}

/// 通过构造函数，将类从模板转为编译的 ClassInstanceType
ClassInstanceType* AstClass::generateClass(
	llvm::LLVMContext& c, 
	std::map<std::string, AstType*>& templateTypes
){
	if (generated) return generated;

	// llvm::raw_os_ostream os(std::clog);
	// 如果是模板的，查看是否有已经生成的
	//if (_templated) {
	//	auto a=_cached.find(reinterpret_cast<intptr_t>(_construstor));
	//	if (a != _cached.end()) return a->second;
	//}
	
	std::string packageName = _context->pathName;
	std::string pathName = _context->pathName;

	std::map< std::string, ClassMemberGen* > members;

	std::string n = name;
	for (auto &i : templateTypes) {
		if (isupper(i.first.at(0))){
			n += "_" + toReadable(i.second->llvmType(c));
		}
	}

	ClassInstanceType* cls = new ClassInstanceType(packageName, name);
	auto *context=cls->makeContext(_context);
	context->thisClass = cls;
	context->templateTypes = templateTypes;

	ThisGen* thisGen = new ThisGen();
	context->setSymbolValue("this", thisGen);
	for (auto i : constValues) {
		context->setSymbolValue(i.first, i.second);
	}

	for (auto &cobj : pathName) {
		if (cobj == '.') cobj = '_';
	}

	cls->_context = context;

	bool body = true;
	// 先创建一个声明
	// 优先使用 C 里面定义的对象
	if (cStructName.empty())
		cls->_type = CLangModule::getStruct(packageName, n);
	else {
		cls->_type = CLangModule::getStruct(cStructName);
		n = cStructName;
	}

	if (!cls->_type) {
		body = false;
		cls->_type = StructType::create(context->context(),  n);
	}

	// 扫描类，初步生成对象
	std::vector< Type* > types = fillMember(context, thisGen, cls);
	fillMemberFunctionsTo(context, cls);

	thisGen->type = cls->_type;
	// int idx = scanClass(cls, context, thisGen, types);

	if (!body) {
		cls->_type->setName(pathName + "_" + cls->name);
		cls->_type->setBody(types);
	}

	if (!_templated) {
		generated = cls;
		//for (auto i : cls->defaultValues) {
		//	dynamic_cast<Lam(i.second)
		//}

	}
	return cls;
}


