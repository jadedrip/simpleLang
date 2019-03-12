#include "stdafx.h"
#include "Ast/AstFunction.h"
#include "FunctionInstance.h"
#include "Ast/AstTuple.h"
#include "Ast/AstReturn.h"
#include "AstContext.h"
#include "utility.h"
#include "Ast/AstPackage.h"
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
	if (!func->getBasicBlockList().empty())
		return;

	// 仅有定义
	if (block.empty()) {
		auto *p=CLangModule::getFunction(name);
		if (!p)
			std::clog << "Warning, not find function " << name << std::endl;
		return;
	}

	auto basicBlock = BasicBlock::Create(context, name, func);

	auto iter = parameters.begin();
	auto i = func->arg_begin();
	if (object) {
		// i->setName("this");
		i++;
	}
	for (; i != func->arg_end(); i++) {
		i->setName(iter->first);
		iter++;
	}

	IRBuilder<> bd(basicBlock);
	for (auto&i : block) {
		i->generate(m, func, bd);
	}
}

llvm::Function * FunctionInstance::generateCode(llvm::Module *m, llvm::LLVMContext & context)
{
	if (func) return func;

	Type* retType = returnType ? returnType : Type::getVoidTy(context);

	std::vector<Type*> param;
	if (object) {
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
	}

	std::string n = name;
	std::for_each(n.begin(), n.end(), [](char &n) { if (n == '.') n = '_'; });

	if (overload && !parameters.empty()) {
		for (auto i : parameters) {
			n.push_back('_');
			Type* tp = const_cast<Type*>(i.second);
			n += getReadable(tp);
		}
	}

	func = m->getFunction(n);
	if (!func) {
		FunctionType *FT = FunctionType::get(retType, param, variable);
		func = Function::Create(FT, Function::ExternalLinkage, n, m);
	}
	return func;
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

