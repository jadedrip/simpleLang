#pragma once
#include "CodeGen.h"
#include "CaseGen.h"

class SwitchIntGen : public CodeGen
{
public:
	CodeGen* expression;
	std::vector<CaseGen*> cases;
public:
	virtual llvm::Value* generateCode(const Generater& generater);
};