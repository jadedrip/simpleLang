#pragma once
#include "AstNode.h"

class AstDelete : public AstNode
{
public:
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstNode* expr;
};

