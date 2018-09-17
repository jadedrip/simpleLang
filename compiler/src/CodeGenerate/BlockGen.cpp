#include "stdafx.h"
#include <llvm/IR/IRBuilder.h>
#include "BlockGen.h"
#include "../AstContext.h"

using namespace llvm;

//BlockGen * BlockGen::createGen(AstContext * context, std::vector<AstNode*> lines, const std::string & name) {
//	return nullptr;
//}

Value * BlockGen::generateCode(Module *m, Function *func, IRBuilder<>&builder)
{
	block = BasicBlock::Create(builder.getContext(), name, func);
	if (br) builder.CreateBr(block);
	builder.SetInsertPoint(block);

	for (auto i : codes) {
		i->generate(m, func, builder);
	}

	if (!next) next = BasicBlock::Create(builder.getContext(), name + "_end", func);
	builder.CreateBr(next);
	builder.SetInsertPoint(next);
	return nullptr;
}
