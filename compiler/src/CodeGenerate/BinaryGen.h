#pragma once
#include "CodeGen.h"

class BinaryGen : public CodeGen							  
{
public:
	BinaryGen(int op, CodeGen*l, CodeGen* r);
private:
	int op;
	CodeGen	*left;
	CodeGen *right;
protected:
	llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
private:
	//llvm::Value* genBooleanCode(llvm::IRBuilder<>& builder, llvm::Value* l, llvm::Value* r);
	//llvm::Value* classBinary(llvm::IRBuilder<>& builder);
};

