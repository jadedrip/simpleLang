#pragma once
#include "CodeGen.h"
#include "LambdaGen.h"

class FunctionInstance;
class GoGen : public CodeGen
{
public:
	GoGen(CodeGen* func);
	std::vector<CodeGen*> globles;
protected:
	virtual llvm::Value* generateCode(const Generater& generater);
private:
	LambdaGen* _func = nullptr;
};

