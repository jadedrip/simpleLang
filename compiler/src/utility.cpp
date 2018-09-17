﻿#include "stdafx.h"
#include "CodeGenerate/BlockGen.h"
#include "utility.h"
#include "Ast/AstNode.h"
#include "AstContext.h"
#include "token.h"

using namespace llvm;

/// 把操作符转换成字符串
std::string operator_to_str(int op) {
	switch (op)
	{
	case LEFTMOVE:
		return "<<";
	case RIGHTMOVE:
		return ">>";
	case URIGHTMOVE:
		return ">>>";
	case LEQ:
		return "<=";
	case REQ:
		return ">=";
	case RGO:
		return "=>";
	case EQ:
		return "==";
	case AEQ:
		return ":=";
	case NOEQ:
		return "!=";
	case OR:
		return "||";
	case AND:
		return "&&";
	case INC:
		return "++";
	case DEC:
		return "--";
	case ARRAY:
		return "->";
	case ISOPT:
		return "is";
	default:
		return std::string(1, (char)op);
	}
}

Value * int_to_bool(IRBuilder<>& builder, Value * v)
{
	auto type=v->getType();
	if (!type->isIntegerTy()) throw std::runtime_error("无法转换成布尔类型");

	int w = type->getScalarSizeInBits();
	if (1 == w ) return v;	// 本来就是布尔类型（i1）

	auto x = IntegerType::get(builder.getContext(), w); 
	Value* zero=ConstantInt::getSigned(x, 0);
	return builder.CreateICmpNE(v, zero);
}

BlockGen * makeCodeGenList(AstContext * parent, std::vector<AstNode*>& lines)
{
	auto x = new BlockGen();
	auto *p = new AstContext(parent);
	for (auto i : lines) {
		auto o=i->makeGen(p);
		x->codes.push_back(o);
	}
	return x;
}

std::string toReadable(llvm::Type * type)
{
	if (type->isIntegerTy()) {
		return "i" + std::to_string(llvm::dyn_cast<llvm::IntegerType>(type)->getBitWidth());
	}
	if (type->isPointerTy()) {
		return toReadable(type->getPointerElementType()) + "_ptr";
	}
	if (type->isStructTy()) {
		auto * ty = llvm::dyn_cast<llvm::StructType>(type);
		std::string n = ty->getName().str();
		return (0 == n.compare(0, 7, "struct.")) ? n.substr(7) : n;
	}
	if (type->isArrayTy()) {
		auto * ty = llvm::dyn_cast<llvm::ArrayType>(type);
		return toReadable(ty->getElementType()) + "_arr";
	}
	return std::to_string(type->getTypeID());
}
