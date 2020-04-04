#pragma once
#include <tuple>
#include "AstContext.h"
#include "../Type/AstType.h"

/**
*	接口区块
*/
class AstInterface : public AstType {
public:
	std::vector<AstNode*> block;
	bool isConcept = false;
};
