#include "stdafx.h"
#include "IsNullGen.h"

IsNullGen::IsNullGen(CodeGen * p) : expr(p) {}

using namespace llvm;
llvm::Value * IsNullGen::generateCode(llvm::Module * m, llvm::Function * func, llvm::IRBuilder<>&builder)
{
	Value *v=expr->generate(m, func, builder);
	return builder.CreateIsNull(v);
}
