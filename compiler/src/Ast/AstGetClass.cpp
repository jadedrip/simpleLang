#include "stdafx.h"
#include "AstContext.h"
#include "AstGetClass.h"

llvm::Type * AstGetClass::llvmType(llvm::LLVMContext & context)
{
	assert(0 && "Can't use get class.");
	return nullptr;
}

llvm::Type * AstGetClass::get(AstContext * parent, llvm::Type * hopeType)
{
	// TODO: 查找正确的类
	return hopeType;
}

