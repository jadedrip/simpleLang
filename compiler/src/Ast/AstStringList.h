#pragma once
#include "AstNode.h"

class AstStringList : public AstNode {
public:
	std::vector<std::string> values;

	virtual CodeGen* makeGen(AstContext* parent);
};