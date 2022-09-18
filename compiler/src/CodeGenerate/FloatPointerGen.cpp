#include "stdafx.h"
#include "FloatPointerGen.h"
using namespace llvm;

FloatPointerGen::FloatPointerGen(llvm::LLVMContext& c, double v, bool isDouble) : _value(v), _isDouble(isDouble) {
	type = isDouble ? llvm::Type::getDoubleTy(c) : llvm::Type::getFloatTy(c);
}

llvm::Value * FloatPointerGen::generateCode(const Generater& generater)
{
	APFloat ap = _isDouble ? APFloat(_value) : APFloat((float)_value);
	auto &c=generater.context();
	auto v = ConstantFP::get(c, ap);
	return v;
}
