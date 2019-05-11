#include "stdafx.h"
#include "AstContext.h"
#include "AstGetClass.h"
#include "../Type/ClassInstanceType.h"

llvm::Type * AstGetClass::llvmType(llvm::LLVMContext & c)
{
	assert(context);
	AstClass* cls=context->findClass(name);
	if (cls) {
		auto* p = context->findCompiledClass("struct." + cls->cStructName);
		if (p) return p->llvmType(c);

		p = context->findCompiledClass(cls->cStructName);
		if (p) return p->llvmType(c);
	}

	auto *p=context->findCompiledClass(name);
	if (p) return p->llvmType(c);
	throw std::runtime_error("Unknown type " + name);
}


