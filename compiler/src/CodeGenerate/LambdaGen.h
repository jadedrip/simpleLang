#pragma once
#include "CodeGen.h"
#include "../Ast/AstFunction.h"
#include "../FunctionInstance.h"

class LambdaGen :
	public CodeGen {
public:
	LambdaGen(AstFunction* func, FunctionInstance* instance);
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
	inline CodeGen* makeCall(AstContext* c, const std::vector<std::pair<std::string, CodeGen*> >& args)
	{
		return _func->makeCall(c, args);
	}
private:
	AstFunction *_func;
	FunctionInstance* _instance;
};

