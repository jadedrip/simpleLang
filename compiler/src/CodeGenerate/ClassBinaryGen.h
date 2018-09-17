#pragma once
#include "CodeGen.h"

class ClassBinaryGen : public CodeGen							  
{
public:
	ClassBinaryGen(int op, CodeGen* l, CodeGen* r);
private:
	int op;
	CodeGen	*left;
	CodeGen *right;
 protected:
	 llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&) { return nullptr; };
};

