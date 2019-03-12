#pragma once

#include "AstNode.h"
#include "Type/AstType.h"

class AstList : public AstNode {
public:
	std::vector<AstNode*> lines;			// ±‰¡ø
};

class AstTypeList : public AstType {
public:
	std::vector<AstType*> lines;
};