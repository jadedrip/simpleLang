#include "stdafx.h"
#include "AstUnary.h"
#include "AstCall.h"
#include "token.h"
#include "utility.h"
#include "CodeGenerate/UnaryGen.h"
#include "CodeGenerate/UnaryIntGen.h"

using namespace llvm;

AstUnary::AstUnary(int o, AstNode * left) : op(o) {
	this->expr = left;
	name = operator_to_str(op);
}

CodeGen * AstUnary::makeGen(AstContext * parent)
{
	auto *p = expr->makeGen(parent);

	auto *c = dyn_cast_or_null<StructType>(p->type);
	if (c) {	// 值是类，那么转换成一个成员函数调用
		//operatorCall = new AstCall();
		//operatorCall->name = "unary " + operator_to_str(op);
		//operatorCall->arguments.push_back(std::make_pair(std::string(), expr));
		//return type = operatorCall->generateType(parent);
	}

	if (!p->type || !p->type->isIntegerTy())
		throw new std::exception("对象不支持一员操作符");

	auto* gem = new UnaryIntGen();
	gem->op = op;
	gem->expr = p;
	return gem;
}

void AstUnary::draw(std::ostream & os) {
	os << nodeId << " -> " << expr->nodeId << std::endl;
	dotLable(os, name);
	expr->draw(os);
}


