#include "stdafx.h"
#include "CodeGen.h"

using namespace llvm;
CodeGen::CodeGen(llvm::Type * t) : type(t) {}
llvm::Value * CodeGen::generate(const Generater& generater)
{
	if (value) return value;
	value = generateCode(generater);
	return value;
}
llvm::Value * CodeGen::load(llvm::IRBuilder<>& builder, llvm::Value * v)
{
	if (v==nullptr) 
		throw std::runtime_error("Load can't load null"); // 无法读取空指针

	auto *t=v->getType();
	if (t->isPointerTy() && !t->getPointerElementType()->isStructTy() )
		return builder.CreateLoad(t->getPointerElementType(), v);
	return v;
}
