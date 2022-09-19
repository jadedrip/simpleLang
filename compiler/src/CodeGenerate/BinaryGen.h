#pragma once
#include "CodeGen.h"

/*
	浮点数的二元操作符生成器
*/
class BinaryGen : public CodeGen							  
{
public:
	BinaryGen(int op, CodeGen*l, CodeGen* r);
private:
	int _op;
	CodeGen	*_left;
	CodeGen *_right;
protected:
	llvm::Value* generateCode(const Generater& generater);
	virtual CodeGen* run(GenContent& content);
private:
	CodeGen* runByStruct(GenContent& content);
	double operDouble(double left, double right);
	//llvm::Value* genBooleanCode(llvm::IRBuilder<>& builder, llvm::Value* l, llvm::Value* r);
	//llvm::Value* classBinary(llvm::IRBuilder<>& builder);
};

