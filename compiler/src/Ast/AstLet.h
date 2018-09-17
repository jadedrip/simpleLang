#pragma once

#include "AstNode.h"

class AstType;
class AstAnnotation;

/// 赋值, 也用于看起来像 type name = value 的节点
class AstLet : public AstNode {
public:
	AstType * type = nullptr;
	AstNode* right = nullptr;			// 右值
	int flag = 0;
	virtual CodeGen* makeGen(AstContext* parent);
public:
	virtual void draw(std::ostream& os);
};
