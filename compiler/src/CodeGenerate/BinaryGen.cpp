#include "stdafx.h"
#include <cassert>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Function.h>
#include "../token.h"
#include "BinaryGen.h"
#include "caster.h"
#include "utility.h"

using namespace llvm;

BinaryGen::BinaryGen(int op, CodeGen * left, CodeGen * right)
	: _op(op), _left(left), _right(right)
{
	// 二元操作符的操作数都是右值
	_left->valueType = ValueType::rvalue;
	_right->valueType = ValueType::rvalue;

	Type* leftType = _left->type;
	Type* rightType = _right->type;

	if (leftType->isDoubleTy())
		type = _left->type;
	else if (rightType->isDoubleTy())
		type = _right->type;
	else if (leftType->isFloatTy())
		type = _left->type;
	else
		type = _right->type;
}

llvm::Value* BinaryGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();
	Value* l = _left->generate(generater);
	l = load(builder, l);
	Value* r = _right->generate(generater);
	r = load(builder, r);

	// 二元操作符左右有空值
	if (l == nullptr || r == nullptr)
		throw std::runtime_error("Binary with null");

	auto lty = l->getType();
	assert(!lty->isPointerTy());
	auto rty = r->getType();
	assert(!rty->isPointerTy());

	int w = std::max(lty->getScalarSizeInBits(), rty->getScalarSizeInBits());

	// 操作数左右必须是相同类型，因此这里进行类型必要的转换
	l = try_cast(builder, type, l);
	r = try_cast(builder, type, r);

	switch (_op) {
	case '+':
		return builder.CreateFAdd(l, r);
	case '-':
		return builder.CreateFSub(l, r);
	case '*':
		return builder.CreateFMul(l, r);
	case '/':
		return builder.CreateFDiv(l, r);
	case '>':
		return builder.CreateFCmpOGT(l, r);
	case '<':
		return builder.CreateFCmpOLT(l, r);
	case EQ:	// ==
		return builder.CreateFCmpOEQ(l, r);
		//case NOEQ:	// !=
		//	return builder.CreateFCmpONE(l, r);
	case REQ:	// >=
		return builder.CreateFCmpOGE(l, r);
	case LEQ:	// <=
		return builder.CreateFCmpOLE(l, r);
	default:
		// 不支持的浮点运算符
		throw std::runtime_error("Unknown operator: " + operator_to_str(_op));
	}
}
