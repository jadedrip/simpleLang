#include "stdafx.h"
#include "caster.h"
#include "ReturnGen.h"
#include "../Type/ClassInstanceType.h"

using namespace llvm;

inline void jump(IRBuilder<>& builder, llvm::BasicBlock* deallocate) 
{
	builder.CreateBr(deallocate);
	builder.SetInsertPoint(deallocate);
}

llvm::Value* ReturnGen::generateCode(const Generater& generater)
{
	auto func = generater.func;
	auto& builder = generater.builder();

	if (returnValues.empty()) {
		jump(builder, generater.deallocate);
		return builder.CreateRetVoid();
	}
	else if (returnValues.size() == 1) {
		auto* p = returnValues.front();
		llvm::Value* v = p->generate(generater);
		if (!p->type->isStructTy())
			v = load(builder, v);
		auto rt = func->getReturnType();

		jump(builder, generater.deallocate);
		return builder.CreateRet(try_cast(builder, rt, v));
	}
	else {
		auto* p = new TupleGen();
		for (auto& i : returnValues) {
			p->elements.push_back(i);
		}

		llvm::Value* v = p->generate(generater);
		v = builder.CreateLoad(v->getType(), v, "return");

		jump(builder, generater.deallocate);
		return builder.CreateRet(v);	// 返回 Tuple 的对象
	}
}
