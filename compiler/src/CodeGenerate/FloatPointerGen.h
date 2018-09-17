#pragma once
#include <llvm/IR/LLVMContext.h>
#include "CodeGen.h"

/// ÓÐ·ûºÅÕûÊý
class FloatPointerGen : public CodeGen
{
public:
	FloatPointerGen(llvm::LLVMContext &c, double v, bool is);
protected:
	llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
private:
	llvm::Value* _value;
};