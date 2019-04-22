#pragma once
#include "CodeGen.h"

class IsNullGen : public CodeGen
{
public:
	IsNullGen(CodeGen* p);
	CodeGen	*expr;
protected:
	llvm::Value* generateCode(const Generater& generater);
};

