#pragma once
#include "AstNode.h"

class AstFunction;
class AstGo : public AstNode {
public:
	AstGo(AstNode* node);
	/// 用来进行模板推导及生成代码
	virtual CodeGen* makeGen(AstContext* parent);
private:
	AstNode* _node;
};

