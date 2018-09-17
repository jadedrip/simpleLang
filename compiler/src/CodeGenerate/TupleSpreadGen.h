#pragma once
#include "CodeGen.h"

class TupleSpreadGen : public CodeGen
{
public:
	TupleSpreadGen(CodeGen* t) : tuple(t) {}
	CodeGen* tuple;
	std::vector<CodeGen*> vars;
protected:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};
