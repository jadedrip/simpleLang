#pragma once
#include "CodeGen.h"
#include "BlockGen.h"

class LoopGen : public CodeGen {
	virtual llvm::Value* generateCode(const Generater& generater);
public:
	CodeGen* let = nullptr;
	CodeGen* cond = nullptr;
	CodeGen* inc = nullptr;

	BlockGen block;
	//std::vector<CodeGen*> block;
};