#include "stdafx.h"
#include "UnaryGen.h"

using namespace llvm;
llvm::Value * UnaryGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	Value* v = expr->generate(m, func, builder);
	assert(v->getType()->isPointerTy());
	auto *ty = v->getType()->getPointerElementType();

	switch (op) {
	case '-':
	{
		assert(ty->isFloatingPointTy());
		Value* zero = ConstantFP::get(builder.getContext(), APFloat(0.0));
		return builder.CreateFSub(zero, v);
	}
	default:
		throw std::runtime_error("不知道的运算符：");
	}
}
