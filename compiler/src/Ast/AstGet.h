#pragma once
#include "AstNode.h"

/* 获取值 */
class AstGet : public AstNode {
public:
	bool right = true;
	virtual CodeGen* makeGen(AstContext* parent);
public:
	virtual void draw(std::ostream& os);
};
