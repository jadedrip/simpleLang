#pragma once

#include "CodeGen.h"
class IndexGen : public CodeGen
{
public:
	CodeGen * expr = nullptr;
	CodeGen * index = nullptr;
	virtual llvm::Value* generateCode(const Generater& generater);
};

