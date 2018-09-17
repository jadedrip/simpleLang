#pragma once
#include "AstNode.h"

/// 一个有类型的值
class AstValue : public AstNode
{
public:
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstNode* value=nullptr;						// 工作区块
};
