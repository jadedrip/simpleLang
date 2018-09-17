#include "stdafx.h"
#include "TupleType.h"

using namespace llvm;
llvm::Type * TupleType::create(llvm::LLVMContext& c, std::vector<llvm::Type*>&& types)
{
	if (types.empty())
		return llvm::Type::getVoidTy(c);
	if (types.size() == 1)
		return types.front();

	return StructType::create(c, types, "tuple");
}
