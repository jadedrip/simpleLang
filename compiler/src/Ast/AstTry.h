#pragma once
#include <tuple>
#include "AstContext.h"
#include "AstTryCatch.h"

/**
*	类区块
*/
class AstTry : public AstNode {
public:
	std::vector<AstNode*> block;
	std::vector<AstTryCatch*> catchs;
	std::vector<AstNode*> finallyBlock;
public:
	virtual void draw(std::ostream& os);
	virtual AstNode* clone();
};
