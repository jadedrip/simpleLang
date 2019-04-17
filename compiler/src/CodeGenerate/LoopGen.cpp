#include "stdafx.h"
#include "LoopGen.h"	   

using namespace llvm;
llvm::Value * LoopGen::generateCode(const Generater& generater)
{
	auto func = generater.func;
	auto& context = func->getContext();

	if (let) let->generate(generater);

	BasicBlock *condBlock = BasicBlock::Create(context, "loop_cond", func);
	//BasicBlock *begin = BasicBlock::Create(context, "loop_begin", func);
	BasicBlock *out = BasicBlock::Create(context, "loop_out", func);

	IRBuilder<> builder(condBlock);
	Generater gen = { generater.module, func, &builder, out };

	// 条件
	auto c = cond->generate(generater);
	c = load(builder, c);

	// 生成循环体
	block.next = condBlock;
	block.name = "loop_block";
	if (inc) block.codes.push_back(inc);
	block.generate(generater);

	builder.CreateCondBr(c, block.block, out);

	builder.SetInsertPoint(out);
	return nullptr;
}
