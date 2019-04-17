#pragma once
#include "CodeGen.h"

class IifGen : public CodeGen
{
public:
	IifGen(CodeGen* cond_, CodeGen* thenValue_, CodeGen* elseValue_);;
	CodeGen	*cond;
	CodeGen	*thenValue;
	CodeGen	*elseValue;
protected:
	llvm::Value* generateCode(const Generater& generater);
};

