#pragma once

#include "AstNode.h"

class AstList : public AstNode {
public:
	std::vector<AstNode*> lines;			// ╠Да©
};
