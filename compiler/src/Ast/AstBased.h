#pragma once
#include "AstNode.h"

/// 注入
/// 基于某个对象的执行块
class AstBased : public AstNode {
public:
	virtual void draw(std::ostream& os);

	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstNode*	expr;
	std::vector<AstNode*> block;
private:
	AstContext* _context;
};
