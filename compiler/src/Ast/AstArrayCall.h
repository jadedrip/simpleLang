#pragma once
#include "AstNode.h"

/**
	调用箭头函数：
		expr->(int v){}
*/
class AstFunction;
class AstArrayCall : public AstNode {
public:
	AstNode* expr = nullptr;
	AstFunction* func = nullptr;
protected:
	virtual CodeGen* makeGen(AstContext* parent);
};