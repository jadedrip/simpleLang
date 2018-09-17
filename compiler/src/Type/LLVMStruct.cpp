#include "stdafx.h"
#include "LLVMStruct.h"

LLVMStructType::LLVMStructType(llvm::StructType * type) : _llvmType(type), AstType(AstType::StructTyID) {
	return;
}

llvm::Type * LLVMStructType::llvmType(llvm::LLVMContext & context) { return _llvmType; }
