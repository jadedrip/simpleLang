#include "stdafx.h"
#include "AstBinary.h"
#include "AstContext.h"
#include "AstStringLiteral.h"
#include "AstIndex.h"
#include "CodeGenerate/LetGen.h"
#include "CodeGenerate/BinaryGen.h"
#include "CodeGenerate/IntegerBinaryGen.h"
#include "CodeGenerate/ClassBinaryGen.h"
#include "CodeGenerate/StringLiteGen.h"
#include "utility.h"
#include "Type/ClassInstanceType.h"
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
	auto &c = parent->context();

	// 判断是否两个字符串相加
	auto lg = dynamic_cast<AstStringLiteral*>(left);
	auto rg = dynamic_cast<AstStringLiteral*>(right);
	if (lg && rg) {
		left->name += right->name;
		delete rg;
		return left->makeGen(parent);
	}
	
	auto l = left->makeGen(parent);
	auto r = right->makeGen(parent);

	if (op == '=') { 
		auto x=dynamic_cast<AstIndex*>(left);
		auto p = new LetGen(l, r);
		p->toArray = x;
		r->escape = true;
		return p;
	}

	auto lt = l->type;
	auto rt = r->type;

	if (lt->isStructTy() || rt->isStructTy()) {
		std::string word = operator_to_word(op);
		std::string n = lt->getStructName();
		auto* cs=parent->findCompiledClass(n);
		if (!cs)
			throw std::runtime_error("Unknown type " + n);
		std::vector<std::pair<std::string, CodeGen*>> args;
		args.push_back(std::make_pair("", r));
		auto *p=cs->makeCall(parent->context(), word, args, l);
		if (!p) throw std::runtime_error("Can't find function " + word);
		return p;
	}

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
