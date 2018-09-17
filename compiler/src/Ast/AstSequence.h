#pragma once

#include "AstList.h"

class AstSequence : public AstNode {
public:
	AstSequence(AstNode* node);
	/// 用来进行模板推导
	virtual CodeGen* makeGen(AstContext* parent);

	std::vector<AstNode*> lines;			// 变量
};
