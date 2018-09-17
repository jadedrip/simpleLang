#pragma once

#include "AstNode.h"

/// 二元操作符 is
/// 用来判断变量是否是指定的类型
class AstIs : public AstNode {
public:
	AstNode* expr;			// 变量
	AstType* type;
public:
	virtual CodeGen* makeGen(AstContext* parent);
	virtual void draw(std::ostream& os);
};
