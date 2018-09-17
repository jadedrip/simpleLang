#pragma once
#include "CodeGen.h"

class TypeOnlyGen : public CodeGen {
public:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&) { return nullptr; };

	TypeOnlyGen(llvm::Type* type) {
		this->type = type;
	}
};