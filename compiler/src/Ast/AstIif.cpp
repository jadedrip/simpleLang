#include "stdafx.h"
#include "AstIif.h"
#include "CodeGenerate/IifGen.h"

void AstIif::draw(std::ostream & os)
{
	dotLable(os, condition->name + "?" );
	dotPointTo(os, thenExpr);
	if (elseExpr) dotPointTo(os, elseExpr);
}

CodeGen * AstIif::makeGen(AstContext * parent)
{
	auto *c = condition->makeGen(parent);
	auto *l = thenExpr->makeGen(parent);
	auto *r = elseExpr ? elseExpr->makeGen(parent) : nullptr;
	return new IifGen(c, l, r);
}
