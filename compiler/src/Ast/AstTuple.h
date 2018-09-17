#pragma once

#include "AstNode.h"

/*
	定义元组 (0, "", 0)
*/
class AstTuple : public AstNode {
public:
	std::vector< AstNode* > elements;	// 元组的元素
public:
	virtual void draw(std::ostream& os);

	virtual CodeGen* makeGen(AstContext* parent);
};
