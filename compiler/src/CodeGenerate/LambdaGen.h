#pragma once
#include "CodeGen.h"
#include "../Ast/AstFunction.h"
#include "../FunctionInstance.h"

class LambdaGen :
	public CodeGen {
public:
	LambdaGen(AstFunction* func, FunctionInstance* instance);
	virtual llvm::Value* generateCode(const Generater& generater);
	inline CodeGen* makeCall(AstContext* c, const std::vector<std::pair<std::string, CodeGen*> >& args)
	{
		return _func->makeCall(c, args);
	}

	CodeGen* object = nullptr;
private:
	AstFunction *_func;
	FunctionInstance* _instance;
};

