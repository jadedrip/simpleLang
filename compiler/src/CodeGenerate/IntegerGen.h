#pragma once
#include <llvm/IR/LLVMContext.h>
#include "CodeGen.h"
	  
/// ÓĞ·ûºÅÕûÊı
class IntegerGen : public CodeGen
{
public:
	int64_t value = 0;
public:
	IntegerGen(llvm::LLVMContext& c, int64_t v, int b = 64);
	IntegerGen(llvm::LLVMContext& c, int v);
protected:
	llvm::Value* generateCode(const Generater& generater);
};