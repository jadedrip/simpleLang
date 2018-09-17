#include "stdafx.h"
#include "AstIsNull.h"
#include "CodeGenerate/IsNullGen.h"

CodeGen * AstIsNull::makeGen(AstContext * parent)
{
	return new IsNullGen(_ptr->makeGen(parent));
}
