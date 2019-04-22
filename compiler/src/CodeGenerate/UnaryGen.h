#pragma once
#include "CodeGen.h"

class UnaryGen : public CodeGen
{
public:
	int op;
	CodeGen	*expr;
protected:
	llvm::Value* generateCode(const Generater& generater);
};

