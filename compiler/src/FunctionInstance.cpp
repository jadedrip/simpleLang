﻿#include "stdafx.h"
#include "Ast/AstFunction.h"
#include "FunctionInstance.h"
#include "Ast/AstTuple.h"
#include "Ast/AstReturn.h"
#include "AstContext.h"
#include "utility.h"
#include "Ast/AstModule.h"
#include "CodeGenerate/ValueGen.h"
#include "CodeGenerate/DefGen.h"
#include "CodeGenerate/ReturnGen.h"
#include "modules.h"

using namespace llvm;
FunctionInstance::FunctionInstance(llvm::Function * f) : func(f)
{
	if (f) {
		name = f->getName();
		returnType = f->getReturnType();
	}
}

void FunctionInstance::generateBody(llvm::Module *m, llvm::LLVMContext & context)
{
	assert(func);
	if (!func->getBasicBlockList().empty())
		return;

	// 仅有定义
	if (block.codes.empty()) {
		auto *p=CLangModule::findFunction(name);
		if (!p)
			std::clog << "Warning, not find function " << name << std::endl;
		return;
	}

	// 注册参数名称
	auto iter = parameters.begin();
	auto i = func->arg_begin();
	if (object) {
		i->setName("it");
		i++;
	}
	for (; i != func->arg_end(); i++) {
		i->setName(iter->first);
		iter++;
	}

	// 分配块
	auto allocBlock = BasicBlock::Create(context, name + "_alloc", func);

	// 函数体
	IRBuilder<> bd(allocBlock);
	Generater g = { m, func, &bd, nullptr };
	block.name = name + ".body";
	block.generate(g);
	// 分配块跳转到函数体
	bd.CreateBr(block.block);
}

llvm::Function * FunctionInstance::generateCode(llvm::Module *m, llvm::LLVMContext & context)
{
	if (func) return func;
	/*
		函数：{函数名}_{返回值类型}_{参数名称}__包全名
		成员函数：{函数名}_{返回值类型}_{参数类型}__{类名}_{包全名}
		静态函数：A_{函数名}_{返回值类型}_{参数类型}__{类名}_{包全名}
	*/
	std::string n = name + "_";

	Type* retType = returnType ? returnType : Type::getVoidTy(context);
	n += getReadable(retType);

	std::vector<Type*> param;
	if (object) { // 是成员函数
		auto *x=PointerType::get(object, 0);
		param.push_back(x);
	}

	for (auto i : parameters) {
		Type* tp = const_cast<Type*>(i.second);
		// 结构一律用指针传
		if (tp->isStructTy()) {
			tp = PointerType::get(tp, 0);
		}
		param.push_back(tp);
		n += getReadable(tp) + "_";
	}
	n += "_";
	if (object) n += getReadable(object);

	if (overload && !parameters.empty()) {
		for (auto i : parameters) {
			n.push_back('_');
			Type* tp = const_cast<Type*>(i.second);
			n += getReadable(tp);
		}
	}

	logger(severity_level::debug) << "Create function: " << n;
	// 仅有定义
	if (block.codes.empty()) {
		func = CLangModule::getFunction(n);
		if (!func)
			std::clog << "Warning, not find function " << name << std::endl;
	}else{
		FunctionType* FT = FunctionType::get(retType, param, _variable);
		func = Function::Create(FT, Function::ExternalLinkage, n, m);
		generateBody(m, context);
	}
	return func;
}

void FunctionInstance::setVariable(bool v) { _variable = v; }

size_t FunctionInstance::getParamenterIndex(const std::string& name) {
	return _paramenterMap[name];
}

//void FunctionInstance::draw(std::ostream & os)
//{
//	std::string n = "func " + name + "(";
//	for (auto i : paremeters) {
//		n += i.type->name + " " + i.name + ",";
//	}
//	if (!paremeters.empty())		n.pop_back();
//	n += ")";
//
//	dotLable(os, n, "octagon");
//	for (auto i : block) {
//		dotPointTo(os, i);
//	}
//}

