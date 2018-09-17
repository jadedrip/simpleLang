#pragma once

#include "AstNode.h"

/// 二元操作符
class AstBinary : public AstNode {
public:
	int op;				// 操作符
	AstNode* left;		// 左值
	AstNode* right;	// 右值
public:
	AstBinary(int o, AstNode* left, AstNode* right);
	virtual CodeGen* makeGen(AstContext* parent);
public:
	virtual void draw(std::ostream& os);
};
