#pragma once
#include "AstNode.h"

/// 常数
class AstConst : public AstNode
{
public:
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstNode * expr;
};
