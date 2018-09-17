#pragma once

#include <vector>
#include <string>
#include "AstNode.h"

class FunctionInstance;
/// 呼叫函数
class AstCall : public AstNode {
public:
	virtual void draw(std::ostream& os);
	std::vector<std::pair<std::string, CodeGen*>> getArguments(AstContext * context);
	virtual CodeGen* makeGen(AstContext* parent);
public:
	CodeGen* object = nullptr;
	std::vector< std::pair<std::string, AstNode*> > arguments;	// 命名参数表
private:
	FunctionInstance* _func = nullptr;
};
