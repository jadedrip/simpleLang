#include "stdafx.h"
#include <cassert>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Function.h>
#include "../token.h"
#include "caster.h"
#include "utility.h"
#include "IntegerBinaryGen.h"
#include "../Type/SIntegerType.h"

using namespace llvm;

IntegerBinaryGen::IntegerBinaryGen(int op, CodeGen * l, CodeGen * r) {
	this->op = op;
	this->left = l;
	this->right = r;
	assert(l->type->isIntegerTy());
	auto lt = dyn_cast<IntegerType>(l->type);
	assert(r->type->isIntegerTy());
	auto rt = dyn_cast<IntegerType>(r->type);

	if (lt->getIntegerBitWidth() < rt->getIntegerBitWidth())
		type = r->type;
	else
		type = l->type;
}

Value * IntegerBinaryGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();
	Value* l = left->generate(generater);
	Value* r = right->generate(generater);
	l = load(builder, l);
	r = load(builder, r);

	if (l == nullptr || r == nullptr)
		throw std::runtime_error("二元操作符左右有空值");

	auto lty = l->getType();
	assert(!lty->isPointerTy());
	auto rty = r->getType();
	assert(!rty->isPointerTy());

	// TODO: 加入布尔型判断
	if (1 == type->getScalarSizeInBits())
		return genBooleanCode(builder, l, r);

	// 操作数左右必须是相同类型，因此这里进行类型必要的转换
	l = try_cast(builder, type, l);
	r = try_cast(builder, type, r);

	switch (op) {
	case LEFTMOVE:
		return builder.CreateShl(l, r);
	case RIGHTMOVE:
		return builder.CreateAShr(l, r);
	case URIGHTMOVE:
		return builder.CreateLShr(l, r);
	case '&':
		return builder.CreateAnd(l, r);
	case '|':
		return builder.CreateOr(l, r);
	case '^':
		return builder.CreateOr(l, r);
	case '+':
		return builder.CreateAdd(l, r);
	case '-':
		return builder.CreateSub(l, r);
	case '*':
		return builder.CreateMul(l, r);
	case '>':
		return builder.CreateICmpSGT(l, r);
	case '<':
		return builder.CreateICmpSLT(l, r);
	case '/':
		return builder.CreateSDiv(l, r);
	case REQ:		// >=
		return builder.CreateICmpSGE(l, r);
	case LEQ:		// <=
		return builder.CreateICmpSLE(l, r);
	case EQ:	// ==
		return builder.CreateICmpEQ(l, r);
	case NOEQ:	// !=
		return builder.CreateICmpNE(l, r);
	default:
		throw std::runtime_error("Unsupported operator：" + operator_to_str(op)); // 不支持的整型运算符
	}
}

llvm::Value * IntegerBinaryGen::genBooleanCode(llvm::IRBuilder<>& builder, llvm::Value * l, llvm::Value * r)
{
	l = int_to_bool(builder, l);
	r = int_to_bool(builder, r);

	switch (op) {
	case EQ:	// ==
		return builder.CreateICmpEQ(l, r);
	case NOEQ:	// !=
		return builder.CreateICmpNE(l, r);
	case AND:
		return builder.CreateAnd(l, r);
	case OR:
		return builder.CreateOr(l, r);
	default:
		throw std::runtime_error("Unsupported operator for boolean：" + operator_to_str(op));
	}
}

