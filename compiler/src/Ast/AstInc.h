#pragma once
#include "AstNode.h"

class AstInc :	public AstNode
{
public:
	virtual CodeGen* makeGen(AstContext* parent);
	virtual void draw(std::ostream& os);
public:
	bool isInc = true;	// Inc or Dec
	AstNode* expr;
};

