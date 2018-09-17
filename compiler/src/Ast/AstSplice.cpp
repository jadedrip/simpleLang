#include "stdafx.h"
#include "AstSplice.h"
#include "AstContext.h"

void AstSplice::draw(std::ostream & os)
{
	dotLable(os, "splice");
}

CodeGen * AstSplice::makeGen(AstContext * parent)
{
	if (begin) begin->makeGen(parent);
	if (end) end->makeGen(parent);
	return expr->makeGen(parent);  // TODO: call func
}


