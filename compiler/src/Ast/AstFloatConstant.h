#pragma once
#include "AstNode.h"

class AstFloatConstant : public AstNode {
public:
	double value = 0;
	bool isDouble = true;
public:
	AstFloatConstant(const char* name, double value, bool isDouble);
public:
	virtual CodeGen* makeGen(AstContext* parent);
}; 