#pragma once
#include "AstType.h"

class LLVMStructType : public AstType
{
public:
	LLVMStructType(llvm::StructType* type);;
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);
public:
	llvm::StructType* _llvmType;
};

