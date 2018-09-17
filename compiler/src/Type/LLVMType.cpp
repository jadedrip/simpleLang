#include "stdafx.h"
#include "LLVMType.h"
#include "SIntegerType.h"

LLVMType::LLVMType(llvm::Type * type)
	: _llvmType(type)
{
	name = "llvm";
}

AstType * LLVMType::get(llvm::Type * type)
{
	if (type->isIntegerTy()) {
		return SIntegerType::get(type->getIntegerBitWidth());
	}
	else if (type->isFloatTy()) {
		return AstType::floatType;
	}
	else if (type->isDoubleTy()) {
		return AstType::doubleType;
	}
	return new LLVMType(type);
}

