#pragma once
#include <tuple>
#include "AstNode.h"

class ClassInstanceType;

/**
*	new 一个对象（带模板）
*	def_type IDENTIFIER '=' block			{ $<expr>$=createNew($1, $2, $4); }
*   IDENTIFIER '=' block						{ $$=createNew(nullptr, $1, $3); }
*/
class AstNew : public AstNode {
public:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstType* type;
	std::vector< AstNode* > blocks;		// 构造参数表
private:
	ClassInstanceType *_cls = nullptr;
};
