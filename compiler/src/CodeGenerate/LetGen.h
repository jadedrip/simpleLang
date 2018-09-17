#pragma once
#include "CodeGen.h"

class LetGen : public CodeGen
{
public:
	LetGen(CodeGen* left_, CodeGen* right_) : left(left_), right(right_) {}
	CodeGen* left = nullptr;
	CodeGen* right = nullptr;
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};