#pragma once

#include "AstContext.h"

/// 条件分支 if
class AstIf : public AstNode {
public:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstNode* condition;
	std::vector<AstNode*> thenBlock;
	std::vector<AstNode*> elseBlock;
};
