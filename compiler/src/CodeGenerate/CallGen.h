#pragma once
#include "CodeGen.h"
#include "../utility.h"

class FunctionInstance;
class CallGen : public CodeGen
{
public:
	CallGen(FunctionInstance* func = nullptr);
	CallGen(CodeGen* gen, llvm::FunctionType*ft, std::vector<CodeGen*>&& attrs);
	CallGen(FunctionInstance* func, std::vector<CodeGen*>&& attrs);
	CallGen(FunctionInstance* func, const std::vector<std::pair<std::string, CodeGen*>>& v, CodeGen* object=nullptr);

	CodeGen* pointerGen = nullptr; // 函数指针
	CodeGen* object = nullptr;

	FunctionInstance* function = nullptr;
	llvm::Value* llvmFunction = nullptr;
	std::vector<CodeGen*> params;
	virtual llvm::Value* generateCode(const Generater& generater);

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
private:
	llvm::FunctionType* funcType = nullptr;
	inline void setRealType(llvm::Type *tp)
	{
		type = tp;
		if (!type->isPointerTy()) return;
		auto *p = type->getPointerElementType();
		if (p->isStructTy())
			type = p;
	}
};

