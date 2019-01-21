#include "stdafx.h"
#include "AstNew.h"
#include "utility.h"
#include "AstClass.h"
#include "AstLet.h"
#include "AstPackage.h"
#include "FunctionInstance.h"
#include "../AstContext.h"
#include "../CodeGenerate/NewGen.h"
#include "../CodeGenerate/GenList.h"
#include "../CodeGenerate/BlockGen.h"
#include "../Type/ClassInstanceType.h"
#include "AstGetClass.h"

void AstNew::draw(std::ostream & os)
{
	std::string n = nodeId;
	dotLable(os, "new " + name, "box");
}

CodeGen * AstNew::makeGen(AstContext * parent)
{
	assert(type);
	// llvm::Type *llvmType = type->llvmType(parent->context());
	AstClass* cls = parent->findClass(type->name);

    // TODO: 通过逃逸分析，判断对象是否要建立在堆栈上
	std::vector<std::pair<std::string, CodeGen*>> args;
	BlockGen* b = new BlockGen();
	for (auto i : blocks) {
		auto* c = i->makeGen(parent);
		if (dynamic_cast<AstLet*>(i))
			args.push_back(std::make_pair(i->name, c));
		else
			args.push_back(std::make_pair(std::string(), c));
	}

	CodeGen* a = cls->makeNew(parent, args);
	if (!a)
		throw std::runtime_error("Can't make class " + cls->name);
	if (!name.empty())
		parent->setSymbolValue(name, a);
	return a;

//std::map<std::string, AstType* > types;
//for (auto i : blocks) {
//	auto* let=dynamic_cast<AstLet*>(i);
//	if (!let) throw std::runtime_error("对象" + name + "初始化中有意外代码");

//	 let->right->makeGen(parent);

//	if (cls) {
//		AstType* t=cls->memberTypes[let->name];
//		auto *c=dynamic_cast<AstGetClass*>(t);
//		if (c) {	// 是模板
//			types[c->name] = type;
//		}
//		else if (!t->instanceOf(type)) {
//			throw std::runtime_error("对象" + name + "的变量"+let->name+"类型不匹配");
//		}
//	}
//}

//if (cls) {
//	auto *p = parent->findClass(x->name);
//	int y = p->templateParameters.size() - x->templateParameters.size();
//	if (y > 0) for (size_t i = p->templateParameters.size() - y; i < p->templateParameters.size(); i++) {
//		// 需要从块中进行模板类型推导
//		auto& value = p->templateParameters.at(i);
//		Parameter param = value.clone();
//		param.type = types[value.name];
//		if (!param.type)
//			throw std::runtime_error("无法推导" + name + "的成员" + param.name + "的类型");
//		x->templateParameters.push_back(param.type);
//	}

//	type = x->get(parent);
//	delete x;
//}
//else {
//	type = parent->findSymbolType(name);
//}

//if (!type) 
//	throw std::runtime_error("构造对象时，无法找到类型无法找到类型" + name);

//parent->setSymbolType(name, type);
//return type;
}

