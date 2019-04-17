#include "stdafx.h"
#include "FloatPointerGen.h"
using namespace llvm;

FloatPointerGen::FloatPointerGen(llvm::LLVMContext & c, double v, bool isDouble) {
	APFloat ap = isDouble ? APFloat(v) : APFloat((float)v);
	_value = ConstantFP::get(c, ap);
	type = _value->getType();
}

llvm::Value * FloatPointerGen::generateCode(const Generater& generater)
{
	return _value;
}
