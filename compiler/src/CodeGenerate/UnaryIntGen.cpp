#include "stdafx.h"
#include "UnaryIntGen.h"

using namespace llvm;
llvm::Value * UnaryIntGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	Value *p = expr->generate(m, func, builder);
	switch (op) {
	case '-':
	{
		Value* zero = ConstantInt::getSigned(p->getType(), 0);
		return builder.CreateSub(zero, p);
	}
	case '~':
	{
		Value* mk = ConstantInt::getSigned(p->getType(), -1);
		return builder.CreateXor(p, mk);
	}
	case '!':
	{
		Value* mk = ConstantInt::getSigned(p->getType(), 1);
		return builder.CreateXor(p, mk);
	}
	default:
		throw std::runtime_error("不支持的运算符");
	}
}
