
#pragma once
#include "CodeGen.h"

class DefGen : public CodeGen {
public:
	DefGen(const std::string& n, llvm::Type* t, CodeGen* value=nullptr, int arraySize=1);
	std::string name;
	CodeGen* value = nullptr;

	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
private:
	llvm::Value* def = nullptr;
	bool isClass = false;
	int arraySize;
};