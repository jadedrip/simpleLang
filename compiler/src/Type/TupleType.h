#pragma once
#include <vector>
#include <llvm/IR/LLVMContext.h>
#include "AstType.h"

class TupleType : public AstType
{
public:
	static llvm::Type* create(llvm::LLVMContext& c, std::vector< llvm::Type* >&& types);
};
