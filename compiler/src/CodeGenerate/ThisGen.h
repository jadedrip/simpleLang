#pragma once
#include "CodeGen.h"

class ThisGen : public CodeGen
{
public:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&)
	{
		auto begin = func->args().begin();
		auto end = func->args().end();
		if (begin == end)
			throw std::runtime_error("Function do not have 'this'.");
		llvm::Argument &it = *begin;
		type = it.getType();
		return &it;
	}
};
