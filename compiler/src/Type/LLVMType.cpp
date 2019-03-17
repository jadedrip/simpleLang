#include "stdafx.h"
#include "LLVMType.h"
#include "SIntegerType.h"

using namespace llvm;
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

AstType* voidPtrType = nullptr;
AstType * LLVMType::getVoidPtr(llvm::LLVMContext & c)
{
	if (!voidPtrType) {
		Type* v = PointerType::getInt8PtrTy(c);
		voidPtrType = get(v);
	}
	return voidPtrType;
}

