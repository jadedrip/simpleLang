#pragma once
#include "CodeGen.h"

class IsNullGen : public CodeGen
{
public:
	IsNullGen(CodeGen* p);
	CodeGen	*expr;
protected:
	llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};

