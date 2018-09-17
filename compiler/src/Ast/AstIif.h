#pragma once

#include "AstContext.h"

/// 条件分支 if
class AstIif : public AstNode {
public:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
	AstIif(AstNode* cond, AstNode* tExpr, AstNode* eExpr = nullptr) : condition(cond), thenExpr(tExpr), elseExpr(eExpr) {}
public:
	AstNode* condition;
	AstNode* thenExpr;
	AstNode* elseExpr;
};
