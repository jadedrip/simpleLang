#include "stdafx.h"
#include "TupleSpreadGen.h"

llvm::Value * TupleSpreadGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<> &builder)
{
	tuple->generate(m, func, builder);
	return nullptr;
}
