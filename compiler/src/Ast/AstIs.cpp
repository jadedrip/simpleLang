#include "stdafx.h"
#include "AstIs.h"
#include "CodeGenerate/StaticTypeGen.h"
#include "../utility.h"
#include "../AstContext.h"

CodeGen * AstIs::makeGen(AstContext * parent)
{
	CodeGen* x = expr->makeGen(parent);
	auto *tp = type->llvmType(parent->context());
	auto o= instanceOf(x->type, tp);
	return new StaticTypeGen(o);
}

void AstIs::draw(std::ostream & os) {
	dotLable(os, "is");
	dotPointTo(os, expr);
//	dotPointTo(os, type);
}
