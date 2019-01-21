#pragma once
#include "AstNode.h"

class DefGen;
class AstDef : public AstNode
{
public:
	AstType* type;
	std::vector<std::pair<std::string, AstNode*>> vars;
private:
	virtual void draw(std::ostream& os);
	virtual CodeGen* makeGen(AstContext* parent);
private:
	CodeGen* makeDefGen(AstContext * parent, AstType* type, const std::string& name, AstNode* var);
};

