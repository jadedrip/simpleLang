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
#include "../FunctionInstance.h"
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
			} else if(p->name== "Finalize"){
				_finalize = p;
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
			continue;
		}				

		// 是否常量
		auto *e = dynamic_cast<AstConst*>(i);
		if (e) {
			constValues[i->name] = i->makeGen(parent);
			continue;
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
	classObject->name = name;
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
	// 把继承的初始值也放入
	auto cp = cls->inherit;
	while (cp) {
		for (auto &i : cp->defaultValues) {
			classObject->defaultValues.insert(i);
		}
		cp = cp->inherit;
	}

	if (_finalize) {
		static std::vector<pair<string, CodeGen*>> emptyTypes;
		classObject->finalize = _finalize->makeCall(parent, emptyTypes, classObject, cls);
	}

	Type *type = classObject->type = cls->llvmType(c);
	//type->print(os);
	//os.flush();
	//std::clog << std::endl;
	//classObject->type = type;
	parent->setCompiledClass(type->getStructName(), cls);
	return classObject;
}

ClassInstanceType * AstClass::generateClass(AstContext* context, std::vector<AstType*>& templateTypes)
{
	string n = cStructName;
	auto &c = context->context();
	
	if (!cStructName.empty()) {
		auto *p=context->findCompiledClass(n);
		if (p) return p;
		
		auto *s=CLangModule::getStruct(n);
		if (s) {
			auto *a = new ClassInstanceType(_context, _context->pathName, n);
			a->_type = s;
			context->setCompiledClass(n, a);
			return a;
		}
	}
	auto *cls = new ClassInstanceType(_context, _context->pathName, name);
	cls->templateTypes = createMappedTemplateTypes(&templateTypes);

	ThisGen* thisGen = new ThisGen();
	cls->setSymbolValue("this", thisGen);
	auto types = fillMember(_context->context(), cls, thisGen);
	fillMemberFunctionsTo(cls);
	cls->_type= StructType::create(c, types, structName());
	return cls;
}

string AstClass::structName()
{
	if (!cStructName.empty()) return cStructName;
	string n = _context->pathName + "_" + name;
	for (char&i : n) { if (i == '.') i = '_'; }
	return n;
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

void AstClass::fillMemberFunctionsTo(ClassInstanceType * cls)
{
	for( auto x : _memberFunctions ){
		// 函数在被调用时才固化
		auto p = isTemplated() ? x->clone() : x;

		p->makeGen(cls);
		//->_parent = context;
		auto it = cls->methds.find(p->name);
		if (it != cls->methds.end()) {
			it->second->overload = true;
			p->overload = true;
		}

		cls->methds.insert(std::make_pair(p->name, p));
	}
}

std::vector<llvm::Type*> AstClass::fillMember(llvm::LLVMContext&c, ClassInstanceType *cls, CodeGen* thisGen)
{
	int idx = 0;
	std::vector<llvm::Type*> types;
	if (cls->inherit) {
		auto *b = cls->inherit->llvmType(c);

		StructType* s = dyn_cast<StructType>(b);
		for_each(s->element_begin(), s->element_end(), [&idx, &types](Type* ty) {
			types.push_back(ty);
			idx++;
			});
		for (auto i : cls->inherit->memberGens) {
			cls->memberGens[i.first] = i.second;
		}
	}
	// String v="1", b
	for (auto a : _members) {
		AstType* v = a.type;

		ClassMemberGen* m = new ClassMemberGen();
		m->object = thisGen;
		m->name = a.name;
		// 如果是非模板变量，确定类型
		if (v->isAuto()) {
			if (!a.defaultValue) {
				auto u = dynamic_cast<AstGetClass*>(v);
				auto *l = cls->findType(u ? u->name : a.name);
				if (!l)
					throw std::runtime_error("成员变量" + a.name + "无法确定类型");
				m->type = l->llvmType(c);
				cls->name += "_" + toReadable(m->type);
			}
		} else {
			auto *l = cls->findType(v->name);
			if (l)
				m->type = l->llvmType(c);
			else
				m->type = v->llvmType(c);
		}
		m->index = idx++;
		cls->memberGens[a.name] = m;
		if (a.defaultValue) {
			auto *g = cls->defaultValues[m->index] = a.defaultValue->makeGen(cls);
			if (v->isAuto())
				m->type = g->type;
		}
		cls->setSymbolValue(a.name, m);
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

	ClassInstanceType* cls = new ClassInstanceType(_context, packageName, name);
	cls->templateTypes = templateTypes;

	ThisGen* thisGen = new ThisGen();
	cls->setSymbolValue("this", thisGen);
	for (auto i : constValues) {
		cls->setSymbolValue(i.first, i.second);
	}

	for (auto &cobj : pathName) {
		if (cobj == '.') cobj = '_';
	}

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
		cls->_type = StructType::create(cls->context(),  n);
	}

	// 如果是继承的，那么需要先生成继承对象
	if (inherit) {
		auto ic = inherit;
		auto* icls = _context->findClass(ic->name);
		std::vector<AstType*> rel;

		if (!ic->templateVars.empty()) {
			for (auto l : ic->templateVars) {
				auto* q = dynamic_cast<AstGetClass*>(l);
				if (q) {
					auto a=cls->findType(q->name);
					if(a){
						rel.push_back(a);
					} else {
						auto cc = cls->findClass(q->name);
						if (cc) {
							auto *h = cc->generateClass(cls, q->templateVars);
							rel.push_back(h);
						}
					}
				}
			}
		}
		cls->inherit = icls->generateClass(cls, rel);
	}

	// 扫描类，初步生成对象
	std::vector< Type* > types = fillMember(c, cls, thisGen);
	fillMemberFunctionsTo(cls);

	thisGen->type = cls->_type;

	if (!body) {
		cls->_type->setName(pathName + "_" + cls->name);
		cls->_type->setBody(std::move(types));
	}

	if (!_templated) {
		generated = cls;
	}
	return cls;
}


