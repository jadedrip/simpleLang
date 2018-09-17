#include "stdafx.h"
#include "AstInc.h"
#include "CodeGenerate/BinaryGen.h"
#include "CodeGenerate/ValueGen.h"
#include "CodeGenerate/LetGen.h"

using namespace llvm;
extern LLVMContext llvmContext;
CodeGen * AstInc::makeGen(AstContext * parent)
{
	auto l = expr->makeGen(parent);
	auto tp = l->type;
	auto value = ConstantInt::getSigned(tp, isInc ? 1 : -1);
	auto r = new ValueGen(value);

	auto *p = new BinaryGen('+', l, r);
	return new LetGen(l, p);
}

void AstInc::draw(std::ostream & os)
{
	dotLable(os, isInc ? "++" : "--");
	dotPointTo(os, expr);
}
