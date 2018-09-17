#pragma once
#include "AstNode.h"
#include "AstCall.h"

/// 类中的 protected 分割线
class AstProtected : public AstNode {
public:
	AstProtected() {
		name = "protected:";
	}
	virtual AstNode* clone() { return this; }
	virtual CodeGen* makeGen(AstContext* parent) { return nullptr;  }
};
