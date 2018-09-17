#include "stdafx.h"
#include "IndexGen.h"

llvm::Value * IndexGen::generateCode(llvm::Module * m, llvm::Function * func, llvm::IRBuilder<>&builder)
{
	auto* a=expr->generate(m, func, builder);
	auto* b = index->generate(m, func, builder);
	auto* p = builder.CreateGEP(a, b);
	return builder.CreateLoad(p);
}
