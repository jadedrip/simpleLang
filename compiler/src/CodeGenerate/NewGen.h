#pragma once
#include "CodeGen.h"

class ClassInstanceType;
class NewGen : public CodeGen
{
public:
	NewGen(llvm::Type* type = nullptr, CodeGen* c = nullptr, CodeGen* len = nullptr);
	CodeGen* construstor = nullptr;
	CodeGen* length = nullptr;
public:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};