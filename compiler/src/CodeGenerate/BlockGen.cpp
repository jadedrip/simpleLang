#include "stdafx.h"
#include <llvm/IR/IRBuilder.h>
#include "BlockGen.h"
#include "../AstContext.h"

using namespace llvm;

Value * BlockGen::generateCode(const Generater& generater)
{
	Generater g = generater;
	auto &c=generater.context();
	
	block = BasicBlock::Create(c, name, generater.func);

	// Îö¹¹¿é
	g.deallocate = BasicBlock::Create(c, "dealloc", generater.func);

	// Ö÷Òª¿é
	IRBuilder<> builder(block);
	g._builder = &builder;

	for (auto i : codes) {
		i->generate(g);
	}
	
	if (next) {
		builder.SetInsertPoint(g.deallocate);
		builder.CreateBr(next);
	}
	return builder.GetInsertBlock();
}


CodeGen* BlockGen::run(GenContent& content)
{
	CodeGen* gen = nullptr;
	for (auto i : codes) {
		gen=i->run(content);
	}
	return gen;
}
