#pragma once
#include "CodeGen.h"

class CLangCallGen : public CodeGen
{
public:
	CLangCallGen(llvm::Function* func, std::vector<CodeGen*>&& attrs);

	llvm::Function* llvmFunction;
	std::vector<CodeGen*> params;

	static llvm::Value* call(
		const Generater& generater, 
		llvm::Function* llvmFunction,
		std::vector<CodeGen*>& params,
		llvm::Type* returnType
	);
protected:
	virtual llvm::Value* generateCode(const Generater& generater);
};
