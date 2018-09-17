#pragma once
#include "AstLet.h"

///定义变量
class AstEnum : public AstNode {
public:
	virtual void draw(std::ostream& os);

	virtual CodeGen* makeGen(AstContext* parent);
public:
	std::vector< AstLet* > values;
};
