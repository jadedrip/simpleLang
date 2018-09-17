#pragma once
#include <llvm/IR/LLVMContext.h>
#include "CodeGen.h"
	  
/// ÓÐ·ûºÅÕûÊý
class IntegerGen : public CodeGen
{
public:
	int64_t value = 0;
public:
	IntegerGen(llvm::LLVMContext& c, int64_t v, int b = 64);
	IntegerGen(llvm::LLVMContext& c, int v);
protected:
	llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};