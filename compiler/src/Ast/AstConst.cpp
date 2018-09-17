#include "stdafx.h"
#include "AstConst.h"
#include "AstContext.h"

CodeGen * AstConst::makeGen(AstContext * parent)
{
	auto* p=expr->makeGen(parent);
	parent->setSymbolValue(name, p);
	return p;
}
