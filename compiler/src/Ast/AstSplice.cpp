#include "stdafx.h"
#include "AstSplice.h"
#include "AstContext.h"
#include "modules.h"
#include "CodeGenerate/CallGen.h"
#include "CodeGenerate/IntegerGen.h"
#include "FunctionInstance.h"

void AstSplice::draw(std::ostream & os)
{
	dotLable(os, "splice");
}

CodeGen * AstSplice::makeGen(AstContext * parent)
{
	llvm::LLVMContext &c = parent->context();
	std::vector<CodeGen*> arg;
	auto *obj = expr->makeGen(parent);
	arg.push_back(obj);

	auto b = begin ? begin->makeGen(parent) : new IntegerGen(c, -1);
	arg.push_back(b);
	auto e = end ? end->makeGen(parent) : new IntegerGen(c, -1);
	arg.push_back(e);

	auto* ty = obj->type;
	if (!ty->isStructTy()) {
		throw std::runtime_error("Can't splice");
	}

	std::string n = ty->getStructName();
	if (n.substr(0, 7) == "struct.")
		n = n.substr(7);
	auto *f=parent->getFunction(n + "_Splice");
	if (!f)
		throw std::runtime_error("No splice object for " + n);
	auto *ins=new FunctionInstance(f);
	return new CallGen(ins, std::move(arg));
}


