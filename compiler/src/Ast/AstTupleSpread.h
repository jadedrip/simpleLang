#pragma once
#include "AstNode.h"

/*
	元组的自动解构
*/
class AstTupleSpread : public AstNode {
public:
	bool def = false;
	std::vector<std::string> vars;	// 列表
	AstNode* tuple;					// 元组
protected:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
};
