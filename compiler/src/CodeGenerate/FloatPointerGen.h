#pragma once
#include <llvm/IR/LLVMContext.h>
#include "CodeGen.h"

/// ÓÐ·ûºÅ¸¡µãÊý
class FloatPointerGen : public CodeGen
{
public:
	FloatPointerGen(llvm::LLVMContext &c, double v, bool is);
protected:
	llvm::Value* generateCode(const Generater& generater);
private:
	llvm::Value* _value;
};