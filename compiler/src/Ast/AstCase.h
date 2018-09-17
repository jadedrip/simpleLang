#pragma once
#include "AstNode.h"

/// switch 的 case 节点
class AstCase : public AstNode
{
public:
	virtual void draw(std::ostream& os);
	virtual void reverseOptimalize(AstContext* parent, int part);
	virtual CodeGen* makeGen(AstContext* parent) { return nullptr; }	// 由 Switch 生成
public:
	std::vector< AstNode* > conditions;	// 条件(所有条件返回的都应该是个可比较的表达式)
	std::vector< AstNode* > block;
public:
	AstContext *_context;
};
