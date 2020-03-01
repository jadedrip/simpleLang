#include "stdafx.h"
#include "UnaryIntGen.h"

using namespace llvm;

UnaryIntGen::UnaryIntGen(int op, CodeGen* expr)
	: _op(op), _expr(expr)
{
	// 一元操作的必须是右值
	_expr->valueType = rvalue;
}

llvm::Value * UnaryIntGen::generateCode(const Generater& generater)
{
	IRBuilder<> builder = generater.builder();

	Value *p = _expr->generate(generater);
	switch (_op) {
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
