#include "stdafx.h"
#include "AstSwitch.h"
#include "AstContext.h"
#include "CodeGenerate\BinaryGen.h"
#include "CodeGenerate\IfGen.h"
#include "CodeGenerate\BlockGen.h"
#include "token.h"

BlockGen * createGen(AstContext * context, std::vector<AstNode*> lines, const std::string & name) {
	auto* block = new BlockGen();
	block->name = name;
	auto bc = new AstContext(context);
	for (auto c : lines) {
		auto*g = c->makeGen(bc);
		block->codes.push_back(g);
	}
	return block;
}


CodeGen* makeCase(AstContext* parent, CodeGen* expr, AstCase* i, CodeGen* next) {
	auto *ifGen = new IfGen();
	if (next) {
		ifGen->elseBlock = new BlockGen();
		ifGen->elseBlock->codes.push_back(next);
	}

	BinaryGen *ifExpr = nullptr;
	std::string n;
	// 生成条件
	for (auto c : i->conditions) {
		auto *g = c->makeGen(parent);
		n = c->name;
		
		auto *cond = new BinaryGen(EQ, expr, g);
		if (ifExpr) {
			ifExpr = new BinaryGen(OR, ifExpr, cond);
		}
		else {
			ifExpr = cond;
		}
	}
	ifGen->condition = ifExpr;

	ifGen->thenBlock = createGen(parent, i->block, "Case_" + n );
	return ifGen;
}

CodeGen * AstSwitch::makeGen(AstContext * parent)
{
	auto *o = expression->makeGen(parent);

	CodeGen* next = nullptr;

	auto iter=cases.rbegin();
	for( ; iter!=cases.rend(); iter++ )	
	{
		auto* i = *iter;
		if (i->conditions.empty()) {	 // default case
			if (next)
				throw std::runtime_error("case after default");
			next = createGen(parent, i->block, "DefaultCase");
		}
		else {
			next = makeCase(parent, o, i, next);
		}
	}

	return next;



	//if (dynamic_cast<SIntegerType*>(o->type)) {
	//	return intSwitchGen(parent, o, cases);
	//}
	//else {
	//	auto x = new SwitchGen();
	//	x->expression = o;
	//	for (auto i : cases) {
	//		CaseGen* p = makeCase(parent, i);
	//		x->cases.push_back(p);
	//	}
	//	return x;
	//}
}

void AstSwitch::draw(std::ostream & os)
{
	dotLable(os, "switch");
	for (auto i : cases) {
		dotPointTo(os, i);
	}
}

