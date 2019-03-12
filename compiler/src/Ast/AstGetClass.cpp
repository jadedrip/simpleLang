#include "stdafx.h"
#include "AstContext.h"
#include "AstGetClass.h"
#include "../Type/ClassInstanceType.h"

llvm::Type * AstGetClass::llvmType(llvm::LLVMContext & c)
{
	assert(context && "Can't use get class.");

	auto *p=context->findCompiledClass(name);
	if (p) return p->llvmType(c);
	throw std::runtime_error("Unknown type " + name);
}


