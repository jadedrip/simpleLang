#include "stdafx.h"
#include "Ast/AstFunction.h"
#include "FunctionInstance.h"
#include "Ast/AstTuple.h"
#include "Ast/AstReturn.h"
#include "AstContext.h"
#include "utility.h"
#include "Ast/AstModule.h"
#include "CodeGenerate/ValueGen.h"
#include "CodeGenerate/ReturnGen.h"
#include "modules.h"

using namespace llvm;
FunctionInstance::FunctionInstance(llvm::Function * f) : func(f)
{
	if (f) {
		name = f->getName().str();
		returnType = f->getReturnType();
	}
}

void FunctionInstance::generateBody(llvm::Module *m, llvm::LLVMContext & context)
{
	if (block.codes.empty()) return;	// 空定义
	assert(func);
	// 不是空的，说明以前生成过
	if (!func->getBasicBlockList().empty()) {
		assert(0);
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
	if (!cName.empty()) {
		func = m->getFunction(cName);
		if (func) return func;
	}

	/*
		生成 C 语言函数名 cName
		函数：{函数名}_{返回值类型}_{参数名称}__包全名
		成员函数：{函数名}_{返回值类型}_{参数类型}__{类名}__{包全名}
		静态函数：A_{函数名}_{返回值类型}_{参数类型}__{类名}__{包全名}
	*/
	assert(returnType);

	if (cName.empty()) {
		cName = name + "_";
		cName += getCompression(returnType);

		if (object) { // 是成员函数
			cName = "M_" + cName;
		}

		if (parameters.empty()) {
			cName += "_X";
		}
		else for (auto i : parameters) {
			Type* tp = const_cast<Type*>(i.second);
			// 结构一律用指针传
			if (tp->isStructTy()) {
				tp = PointerType::get(tp, 0);
			}
			cName += "_" + getCompression(tp);
		}
		if (object) cName += "__" + getCompression(object);
		if(!packageName.empty()) cName+="__" + packageName;
	}

	// 确定参数
	std::vector<Type*> param;
	if (object) { // 是成员函数
		auto* x = PointerType::get(object, 0);
		param.push_back(x);
	}
	for (auto i : parameters) {
		Type* tp = const_cast<Type*>(i.second);
		// 结构一律用指针传
		if (tp->isStructTy()) {
			tp = PointerType::get(tp, 0);
		}
		param.push_back(tp);
	}

	logger(severity_level::debug) << "Create function: " << cName;
	func = m->getFunction(cName);
	if (func) return func;	// 先考虑已经存在的

	// 先创建定义，PS: 跨模块的情况下需要 link
	FunctionType* FT = FunctionType::get(returnType, param, _variable);
	func = Function::Create(FT, Function::ExternalLinkage, cName, m);
	// 仅有定义
	if (block.codes.empty()) {
		auto f = CLangModule::getFunction(cName);
		if (!f)	// 其他模块也找不到？
			std::clog << "Warning, not find function " << name << std::endl;
	}else{
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

