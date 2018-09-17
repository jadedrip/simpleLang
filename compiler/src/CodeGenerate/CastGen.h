#pragma once
#include "CodeGen.h"

class CastGen : public CodeGen
{
public:
	CastGen(llvm::Type* t, CodeGen* v);

	CodeGen* value;
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};

