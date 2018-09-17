#pragma once

#include "AstNode.h"
#include "token.h"

class AstCall;
/// 一元操作符（符号写在前面）
class AstUnary : public AstNode {
public:
	int op;				// 操作符
	AstNode* expr;		// 变量
	bool after = false;	
public:
	AstUnary(int o, AstNode* left);
protected:
	virtual CodeGen* makeGen(AstContext* parent);
	virtual void draw(std::ostream& os);
private:
	AstCall* operatorCall = nullptr;
};
