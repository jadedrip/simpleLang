#pragma once
#include "CodeGen.h"
#include "../utility.h"

class FunctionInstance;
class CallGen : public CodeGen
{
public:
	CallGen(FunctionInstance* func = nullptr);
	CallGen(FunctionInstance* func, std::vector<CodeGen*>&& attrs);
	CallGen(FunctionInstance* func, std::vector<std::pair<std::string, CodeGen*>>& v, CodeGen* object=nullptr);

	FunctionInstance* function = nullptr;
	llvm::Function* llvmFunction = nullptr;
	std::vector<CodeGen*> params;
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);

	template<typename T1, typename... T2> static void convertToValue(std::vector<llvm::Value*>& vec, T1 p, T2... arg)
	{
		vec.push_back(toLLValue(p));
		convertToValue(vec, arg...);
	}
	static void convertToValue(std::vector<llvm::Value*>& vec){}

	template< class ... Params >
	static llvm::CallInst* call(llvm::IRBuilder<>& builder, llvm::Function* func, Params ... funcParams)
	{
		std::vector<llvm::Value*> values;
		convertToValue(values, funcParams...);
		return callFunc(builder, func, values);
	}

	static llvm::CallInst* callFunc(llvm::IRBuilder<>& builder, llvm::Function* func, std::vector<llvm::Value*>& values);
};

