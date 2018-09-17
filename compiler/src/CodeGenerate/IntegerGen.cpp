#include "stdafx.h"
#include "IntegerGen.h"

using namespace llvm;
IntegerGen::IntegerGen(llvm::LLVMContext& c, int64_t v, int b)
	: value(v){
	type = IntegerType::get(c, b);
}

IntegerGen::IntegerGen(llvm::LLVMContext& c, int v) : value(v) {
	type = IntegerType::get(c, 32);
}

Value * IntegerGen::generateCode(Module * m, Function * func, IRBuilder<>&builder)
{
	auto &context = builder.getContext();
	if(hopeType)
		return ConstantInt::get(hopeType, value);
	return ConstantInt::get(type, value);
}
