#pragma once
#include "CodeGen.h"

class CLangCallGen : public CodeGen
{
public:
	CLangCallGen(llvm::Function* func, std::vector<CodeGen*>&& attrs);

	llvm::Function* llvmFunction;
	std::vector<CodeGen*> params;
protected:
	virtual llvm::Value* generateCode(const Generater& generater);
};
