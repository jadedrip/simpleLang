#pragma once
#include "AstNode.h"

class AstSplice :
	public AstNode
{
public:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstNode* expr;
	AstNode* begin = nullptr;
	AstNode* end = nullptr;
};

