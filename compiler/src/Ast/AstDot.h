#pragma once
#include "AstNode.h"

/// 点操作符
/// 例子：	
///		a.open() 
///		a.val 
///		org.silang.System.print("");
class AstDot : public AstNode {
public:
	AstNode* object;
	AstNode* right;
	AstDot(AstNode* object, AstNode*right);
public:
	virtual CodeGen* makeGen(AstContext* parent);
	virtual void draw(std::ostream& os);
};
