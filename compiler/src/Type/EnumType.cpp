#include "stdafx.h"
#include <llvm/IR/DerivedTypes.h>
#include "EnumType.h"
#include "EnumContent.h"

std::string EnumType::uniqueName() {
	return "W4";
}

llvm::Type * EnumType::llvmType(llvm::LLVMContext & context)
{
	return llvm::IntegerType::get(context, 32);
}

AstContext * EnumType::makeContext(AstContext * context, CodeGen *)
{
	return new EnumContext(context, std::move(enums));
}
