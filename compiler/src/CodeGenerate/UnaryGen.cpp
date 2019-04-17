#include "stdafx.h"
#include "UnaryGen.h"

using namespace llvm;
llvm::Value * UnaryGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();
	auto& c = generater.context();


	Value* v = expr->generate(generater);
	assert(v->getType()->isPointerTy());
	auto *ty = v->getType()->getPointerElementType();

	switch (op) {
	case '-':
	{
		assert(ty->isFloatingPointTy());
		Value* zero = ConstantFP::get(c, APFloat(0.0));
		return builder.CreateFSub(zero, v);
	}
	default:
		throw std::runtime_error("不知道的运算符：");
	}
}
