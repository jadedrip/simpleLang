#pragma once
#include "AstNode.h"
#include "AstClass.h"

/* ªÒ»°¿‡ */
class AstGetClass : public AstType {
public:
	// AstClass* toClass = nullptr;
	std::vector<AstType*> templateVars;
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);
	AstContext * context = nullptr;
};
