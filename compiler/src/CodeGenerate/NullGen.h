#pragma once
#include "CodeGen.h"

class NullGen : public CodeGen
{
public:
	NullGen(llvm::Type*);
public:
	virtual llvm::Value* generateCode(const Generater& generater);
};

