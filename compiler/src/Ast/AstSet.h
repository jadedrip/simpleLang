#pragma once

#include "AstNode.h"

/// 属性 Set 
/// set( int a )
class AstSet : public AstNode {
public:
	AstType* type;
	std::vector<AstNode*> block;
public:
	virtual CodeGen* makeGen(AstContext* parent);
	virtual void draw(std::ostream& os);
};
