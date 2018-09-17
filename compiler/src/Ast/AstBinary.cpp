#include "stdafx.h"
#include "AstBinary.h"
#include "AstContext.h"
#include "CodeGenerate/BinaryGen.h"
#include "CodeGenerate/IntegerBinaryGen.h"
#include "CodeGenerate/ClassBinaryGen.h"
#include "CodeGenerate/StringLiteGen.h"
#include "utility.h"
#include <exception>

using namespace llvm;

AstBinary::AstBinary(int o, AstNode * left, AstNode * right) : op(o) {
	this->left = left;
	this->right = right;
	name.push_back((char)o);
}

inline bool isNumber(Type* ty) {
	return ty->isIntegerTy() || ty->isFloatingPointTy();
}

CodeGen* AstBinary::makeGen(AstContext * parent)
{
	auto l = left->makeGen(parent);
	auto r = right->makeGen(parent);

	// 判断是否两个字符串相加
	auto lg = dynamic_cast<StringLiteGen*>(l);
	auto rg = dynamic_cast<StringLiteGen*>(r);
	if (lg && rg) {
		lg->append(rg);
		delete rg;
		return lg;
	}

	auto lt = l->type;
	auto rt = r->type;
	if (lt->isStructTy() || rt->isStructTy())
		return new ClassBinaryGen(op, l, r);

	if (lt->isIntegerTy() && rt->isIntegerTy()) {
		return new IntegerBinaryGen(op, l, r);
	}
	else if (isNumber(lt) && isNumber(rt)) {
		return new BinaryGen(op, l, r);
	}

	// 理论上不应该到这里
	throw std::runtime_error("Binary opertor with unknown type");
}

void AstBinary::draw(std::ostream & os)
{
	dotPointTo(os, left);
	dotPointTo(os, right);

	dotLable(os, operator_to_str(op));
}
