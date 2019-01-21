#include "stdafx.h"
#include "ClassContext.h"
#include "AstDef.h"
#include "AstClass.h"
#include "AstFunction.h"
#include "AstProtected.h"
#include "AstDef.h"
#include "AstCall.h"
#include "AstConst.h"
#include "../Type/AutoType.h"
#include "../Type/ClassInstanceType.h"
#include "CodeGenerate/NewGen.h"
#include "CodeGenerate/DefGen.h"
#include "CodeGenerate/ThisGen.h"
#include "modules.h"

using namespace llvm;

CodeGen * AstClass::makeGen(AstContext * parent)
{
	parent->setClass(name, this);
	_context = parent;

	for (auto i : block) {
		// 检测构造函数
		auto *p=dynamic_cast<AstFunction*>(i);
		if (p) {
			p->_cls = this;
			if (p->name == "Init") 
				_construstor.push_back(p);
			continue;
		}	  
		// 检测是否模版类
		auto *q = dynamic_cast<AstDef*>(i);
		if (q) {
			if (!q->type || AstType::AutoTyId == q->type->type())
				_templated = true;
		}				

		// 是否常量
		auto *e = dynamic_cast<AstConst*>(i);
		if (e) {
			constValues[i->name] = i->makeGen(parent);
		}
	}

	return nullptr;
}

CodeGen * AstClass::makeNew(AstContext* parent, std::vector<std::pair<std::string, CodeGen*>>& args)
{						  
	llvm::LLVMContext &c = parent->context();
	NewGen* classObject = new NewGen();		// TODO: malloc

	auto *thisGen = new ThisGen();
	if (!_construstor.empty()) {
		bool match = false;
		for (auto x : _construstor) {
			x->genDefaultValue(_context);
			AstFunction::OrderedParameters *ordered = x->orderParameters(parent->context(), args);
			if (!args.empty() && !ordered)
				continue;  // 不匹配
						 // 推导类
			match = true;
			auto cls = generateClass(c, thisGen); // 生成类（注意，这时部分变量可能还是模板的

			// 创建构造函数，并设置所有模板变量
			CodeGen* call = x->makeCall(
				c,
				ordered->parameters,
				thisGen,
				cls
			);

			classObject->type = cls->llvmType(c);
			classObject->construstor = call;
		}
		if (!match) return nullptr;
	}else{
		auto a = generateClass(c, thisGen);
		auto t = classObject->type = a->llvmType(c);
		parent->setCompiledClass(t->getStructName(), a);
	}
		
	if (args.empty() || classObject->construstor) {
		return classObject;
	}
	throw std::runtime_error("类" + name + "没有合适的构造函数");
}

int AstClass::scanClass(ClassInstanceType* cls, AstContext* context, CodeGen* thisGen)
{
	context->setSymbolValue("this", thisGen);
	bool isProctected = false;
	int idx = 0;
	auto &c=context->context();

	for (auto i : block) {
		// 创建函数、变量索引
		auto x = dynamic_cast<AstFunction*>(i);
		if (x) {
			// 函数在被调用时才固化
			// TODO: 貌似应该复制一份？
			x->_parent = context;
			cls->methds.insert(std::make_pair(x->name, x));
			continue;
		}

		std::vector< CodeGen* > initGen;
		auto v = dynamic_cast<AstDef*>(i);
		if (v) {
			// String v="1", b
			for (auto a : v->vars) {
				ClassMemberGen* m = new ClassMemberGen();
				m->object = thisGen;
				m->name = v->name;
				m->isProtected = isProctected;
				// 如果是非模板变量，确定类型
				if (!v->type->isAuto())
					m->type = v->type->llvmType(c);
				m->index = idx++;
				cls->memberGens[a.first] = m;
				if (a.second)
					cls->defaultValues[a.first] = a.second->makeGen(_context);
				context->setSymbolValue(a.first, m);
			}
			continue;
		}

		auto y = dynamic_cast<AstProtected*>(i);
		if (y) {
			isProctected = true;
			continue;
		}

		auto cst = dynamic_cast<AstConst*>(i);
		if (cst) {
			continue;
		}

		throw std::runtime_error("类内有未知的定义");
	}

	for (auto i : constValues) {
		context->setSymbolValue(i.first, i.second);
	}
	return idx;
}

/// 通过构造函数，将类从模板转为编译的 ClassInstanceType
ClassInstanceType* AstClass::generateClass(llvm::LLVMContext& c, CodeGen* thisGen)
{
	if (_generated) return _generated;

	// 如果是模板的，查看是否有已经生成的
	//if (_templated) {
	//	auto a=_cached.find(reinterpret_cast<intptr_t>(_construstor));
	//	if (a != _cached.end()) return a->second;
	//}
	
	std::string packageName = _context->pathName;
	std::string pathName = _context->pathName + "." + name;

	std::vector< Type* > types;
	std::map< std::string, ClassMemberGen* > members;

	ClassInstanceType* cls = new ClassInstanceType(packageName, name);
	auto *context=cls->makeContext(_context);
	// 扫描类，初步生成对象
	int idx = scanClass(cls, context, thisGen);

	if (!_templated) {
// 优先使用 C 里面定义的对象
		for (auto &cobj : pathName) {
			if (cobj == '.') cobj = '_';
		}
		cls->_type = CLangModule::getStruct(packageName, name);
		if (!cls->_type) {
			cls->_type = StructType::create(context->context(), types, pathName);
		}
		_generated = cls;
	}
	return cls;
}


