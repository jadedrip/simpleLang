#pragma once

#include "AstLoop.h"

/*
	for each 类型循环
	注：元素变量 i 不允许在循环外定义
		for( var i: list )
	*/
class AstForeach : public AstNode {
public:
	virtual void draw(std::ostream& os);
public:
	std::string variable;		// 元素变量名
	AstNode* container;		// 容器
	std::vector<AstNode*>	block;
};
