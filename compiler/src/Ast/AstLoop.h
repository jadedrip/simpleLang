#pragma once

#include "AstNode.h"

/*
	循环, while, for 形式的基类，判断在循环开始处
	for( int i=0; i<10; i++){} 实际上等同
	int i=0;
	while( i<10 ){
		...
		i++;
	}
*/
class AstLoop : public AstNode {
public:
	virtual CodeGen* makeGen(AstContext* parent);
	virtual void draw(std::ostream& os);
public:
	AstNode*	let = nullptr;			// 赋值
	AstNode* cond = nullptr;	// 前置条件判断
	AstNode* inc = nullptr;
	std::vector<AstNode*> block;	// 循环体
private:
	AstContext* _context;
};
