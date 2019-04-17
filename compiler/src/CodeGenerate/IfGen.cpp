#include "stdafx.h"
#include "IfGen.h"
#include "BlockGen.h"

using namespace llvm;

llvm::Value * IfGen::generateCode(const Generater& generater)
{
	auto func = generater.func;
	auto& builder = generater.builder();
	auto m = generater.module;

	_funcBlock = &(func->getEntryBlock());
	Value* cond = condition->generate(generater);
	cond = load(builder, cond);
	auto tp = cond->getType();
	if (!tp->isIntegerTy(1))
		cond = builder.CreateTrunc(cond, builder.getInt1Ty());

	auto &context = builder.getContext();
	// 创建退出块
	BasicBlock* outBB = BasicBlock::Create(context, "EndIf", func);
	thenBlock->next = outBB;
	thenBlock->generate(generater);

	if (elseBlock) {
		elseBlock->next = outBB;
		elseBlock->generate(generater);
	}

	builder.CreateCondBr(cond, thenBlock->block, elseBlock ? elseBlock->block : outBB);
	builder.SetInsertPoint(outBB);
	return outBB;
}
