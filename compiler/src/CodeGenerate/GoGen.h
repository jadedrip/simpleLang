#pragma once
#include "CodeGen.h"
#include "LambdaGen.h"

class FunctionInstance;
class GoGen : public CodeGen
{
public:
	GoGen(CodeGen* func);
protected:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
private:
	LambdaGen* _func = nullptr;
};

