#pragma once
#include <tuple>
#include "AstNode.h"

/**
*	catch区块
*	catch( MyE, MyB: e){}
*/
class AstTryCatch : public AstNode {
public:
	std::vector<AstType*> exception_types;
	std::vector<AstNode*> block;
public:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent) { return nullptr; }
};
