#pragma once

#include "AstNode.h"

/// 二元操作符
class AstAnnotation : public AstNode {
public:
	AstNode * defaultValue = nullptr;
	std::map<std::string, AstNode*> attrs;
};
