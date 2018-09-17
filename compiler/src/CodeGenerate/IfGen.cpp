#include "stdafx.h"
#include "IfGen.h"
#include "BlockGen.h"

using namespace llvm;

llvm::Value * IfGen::generateCode(Module *m, Function *func, llvm::IRBuilder<>&builder)
{
	_funcBlock = &(func->getEntryBlock());
	Value* cond = condition->generate(m, func, builder);
	cond = load(builder, cond);
	auto tp = cond->getType();
	if (!tp->isIntegerTy(1))
		cond = builder.CreateTrunc(cond, builder.getInt1Ty());

	auto &context = builder.getContext();
	auto *current = builder.GetInsertBlock();

	BasicBlock *outBB = BasicBlock::Create(context, "EndIf", func);
	thenBlock->br = false;
	thenBlock->next = outBB;
	thenBlock->generate(m, func, builder);

	if (elseBlock) {
		elseBlock->br = false;
		elseBlock->next = outBB;
		elseBlock->generate(m, func, builder);
	}

	builder.SetInsertPoint(current);
	builder.CreateCondBr(cond, thenBlock->block, elseBlock ? elseBlock->block : outBB);
	builder.SetInsertPoint(outBB);
	return outBB;
}
