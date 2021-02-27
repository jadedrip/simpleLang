#include "stdafx.h"
#include "AstDelete.h"
#include "CodeGenerate/CallGen.h"
#include "modules.h"
#include "FunctionInstance.h"

CodeGen * AstDelete::makeGen(AstContext * parent)
{
	auto *func= CLangModule::getFunction("sl", "freeObject");
	auto *p = new CallGen(new FunctionInstance(func));
	p->params.push_back(expr->makeGen(parent));
	return p;
}
