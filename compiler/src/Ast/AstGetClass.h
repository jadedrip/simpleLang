#pragma once
#include "AstNode.h"
#include "AstClass.h"

/* ªÒ»°¿‡ */
class AstGetClass : public AstType {
public:
	// AstClass* toClass = nullptr;
	std::vector<std::string> path;
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);

	llvm::Type* get(AstContext * parent, llvm::Type* hopeType = nullptr);
};
