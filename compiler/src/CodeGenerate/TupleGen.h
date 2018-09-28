#pragma once
#include "CodeGen.h"

class TupleGen : public CodeGen
{
public:
	std::vector<CodeGen*> elements;
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};
