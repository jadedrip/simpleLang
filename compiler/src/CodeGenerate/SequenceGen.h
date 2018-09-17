#pragma once
#include "CodeGen.h"

class SequenceGen : public CodeGen
{
public:
	std::vector<CodeGen	*> values;
protected:
	llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};

