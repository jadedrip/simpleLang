#pragma once
#include "CodeGen.h"

/**
* 两个整数的运算
*/
class IntegerBinaryGen : public CodeGen
{
public:
	int op;
	CodeGen	*left;
	CodeGen *right;

	IntegerBinaryGen(int op, CodeGen*l, CodeGen* r);
protected:
	llvm::Value* generateCode(const Generater& generater);
private:
	llvm::Value* genBooleanCode(llvm::IRBuilder<>& builder, llvm::Value* l, llvm::Value* r);
};

