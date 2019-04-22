#pragma once
#include "CodeGen.h"

class TupleGen : public CodeGen
{
public:
	std::vector<CodeGen*> elements;
	virtual llvm::Value* generateCode(const Generater& generater);
};
