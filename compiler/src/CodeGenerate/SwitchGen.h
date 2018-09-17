#pragma once
#include "CodeGen.h"
#include "CaseGen.h"

class SwitchGen : public CodeGen {
public:
	CodeGen* expression;
	std::vector<CaseGen*> cases;
public:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};