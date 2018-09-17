#pragma once
#include "AstNode.h"
class AstIsNull : public AstNode
{
public:
	AstIsNull(AstNode* expr) : _ptr(expr) {};
	virtual CodeGen* makeGen(AstContext* parent);
private:
	AstNode* _ptr;
};

