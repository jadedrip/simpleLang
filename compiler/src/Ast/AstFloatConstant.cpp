#include "stdafx.h"
#include "AstFloatConstant.h"	
#include "CodeGenerate/FloatPointerGen.h"
#include "AstContext.h"

AstFloatConstant::AstFloatConstant(const char * n, double v, bool is) : value(v), isDouble(is)
{
	name = n;
}

CodeGen * AstFloatConstant::makeGen(AstContext * parent)
{
	return new FloatPointerGen(parent->context(), value, isDouble);
}
