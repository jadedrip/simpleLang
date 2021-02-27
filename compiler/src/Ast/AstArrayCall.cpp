#include "stdafx.h"
#include "AstArrayCall.h"
#include "AstCall.h"
#include "Type/ClassInstanceType.h"
#include "CodeGenerate/LambdaGen.h"

CodeGen * AstArrayCall::makeGen(AstContext * parent)
{
	auto &c = parent->context();
	CodeGen* obj = expr->makeGen(parent);

	auto *ct=parent->findCompiledClass(obj->type->getStructName().str());
	auto *l = func->makeGen(parent);

	std::vector<std::pair<std::string, CodeGen*>> args;
	args.push_back(std::make_pair("", l));
	return ct->makeCall(c, "ARRAY", args, obj);
}
