#include "stdafx.h"
#include "LoopGen.h"	   

using namespace llvm;
llvm::Value * LoopGen::generateCode(llvm::Module *m, llvm::Function *func, IRBuilder<>&builder)
{
	if (let) let->generate(m, func, builder);

	BasicBlock *condBlock = BasicBlock::Create(builder.getContext(), "loop_cond", func);
	BasicBlock *begin = BasicBlock::Create(builder.getContext(), "loop_begin", func);
	BasicBlock *out = BasicBlock::Create(builder.getContext(), "loop_out", func);

	builder.CreateBr(condBlock);

	builder.SetInsertPoint(condBlock);
	auto c = cond->generate(m, func, builder);
	c = load(builder, c);
	builder.CreateCondBr(c, begin, out);

	builder.SetInsertPoint(begin);
	for (auto i : block) {
		i->generate(m, func, builder);
	}

	if (inc) inc->generate(m, func, builder);
	builder.CreateBr(condBlock);
	builder.SetInsertPoint(out);
	return nullptr;
}
