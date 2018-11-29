#pragma once
#include "AstClass.h"

///定义变量
class AstEnum : public AstClass {
public:
	virtual void draw(std::ostream& os);

	virtual CodeGen* makeGen(AstContext* parent);
public:
	std::vector< AstLet* > values;
};
