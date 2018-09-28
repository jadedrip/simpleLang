#pragma once
#include <vector>
#include <llvm/IR/LLVMContext.h>
#include "AstType.h"

class TupleType : public AstType
{
public:
	static llvm::Type* create(llvm::LLVMContext& c, const std::vector< llvm::Type* >& types);
};

llvm::StructType* makeStruct(llvm::LLVMContext& c, const std::vector<llvm::Type*> & types);