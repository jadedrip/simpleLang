#include "stdafx.h"
#include "AstValue.h"

CodeGen * AstValue::makeGen(AstContext * parent)
{
	return value ? value->makeGen(parent) : nullptr;
}

