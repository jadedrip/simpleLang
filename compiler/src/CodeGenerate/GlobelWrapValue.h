#pragma once
#include "CodeGen.h"

/*
   协程参数包装
*/
class GoWrapValue : public CodeGen
{
public:
	GoWrapValue(size_t index, llvm::Type* type);

	virtual llvm::Value* generateCode(const Generater& generater);
private:
	size_t _index;
};
