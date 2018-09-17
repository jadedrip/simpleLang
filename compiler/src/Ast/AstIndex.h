#pragma once
#include <vector>
#include "AstNode.h"
class AstIndex : public AstNode
{
public:
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstNode* expr;
	AstNode* index;
};

