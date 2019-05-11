#pragma once
#include <tuple>
#include "AstNode.h"

class ClassInstanceType;

/**
*	new 一个数组
*	def_type IDENTIFIER '=' block			{ $<expr>$=createNew($1, $2, $4); }
*   IDENTIFIER '=' block						{ $$=createNew(nullptr, $1, $3); }
*/
class AstNewArray : public AstNode {
public:
	//virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
public:
	AstType* type;
	AstNode* expr;
private:
	ClassInstanceType *_cls = nullptr;
};
