#pragma once
#include <vector>
#include "AstNode.h"


/**
*	定义执行 return 时的动作。
*/
class AstReturn : public AstNode {
public:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
public:
	std::vector<AstNode*> returnValues;	// 返回的值（注：可能是个元组）
};
