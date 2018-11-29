#pragma once
#include "AstNode.h"

class AstGetConstValue : public AstNode
{
public:
	AstGetConstValue(const char* className, const char* member);
private:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
private:
	std::string _className;
	std::string _member;
};
