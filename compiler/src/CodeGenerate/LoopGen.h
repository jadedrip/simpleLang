#pragma once
#include "CodeGen.h"

class LoopGen : public CodeGen {
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
public:
	CodeGen* let = nullptr;
	CodeGen* cond = nullptr;
	CodeGen* inc = nullptr;

	std::vector<CodeGen*> block;
};