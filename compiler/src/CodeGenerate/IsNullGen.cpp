#include "stdafx.h"
#include "IsNullGen.h"

IsNullGen::IsNullGen(CodeGen * p) : expr(p) {}

using namespace llvm;
llvm::Value * IsNullGen::generateCode(const Generater& generater)
{
	Value *v=expr->generate(generater);
	return generater.builder().CreateIsNull(v);
}
