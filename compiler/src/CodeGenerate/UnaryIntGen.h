#pragma once
#include "CodeGen.h"

class UnaryIntGen : public CodeGen
{
public:
	UnaryIntGen(int op, CodeGen* expr);
private:
	int _op;
	CodeGen* _expr;
protected:
	llvm::Value* generateCode(const Generater& generater);
};


