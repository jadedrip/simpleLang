#include "stdafx.h"
#include <cassert>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Function.h>
#include "../token.h"
#include "BinaryGen.h"
#include "caster.h"
#include "utility.h"

using namespace llvm;

BinaryGen::BinaryGen(int op, CodeGen * l, CodeGen * r) {
	this->op = op;
	left = l;
	right = r;

	Type* leftType = l->type;
	Type* rightType = r->type;

	if (leftType->isDoubleTy())
		type = l->type;
	else if (rightType->isDoubleTy())
		type = r->type;
	else
		type = l->type;
	l->hopeType = r->hopeType = type;
}

llvm::Value * BinaryGen::generateCode(Module *m, Function *function, IRBuilder<>&builder) {
	Value* l = left->generate(m, function, builder);
	l = load(builder, l);
	Value* r = right->generate(m, function, builder);
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

	switch (op) {
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
			throw std::runtime_error("Unknown operator: " + operator_to_str(op));
	}
}
