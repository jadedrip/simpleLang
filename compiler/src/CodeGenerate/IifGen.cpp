#include "stdafx.h"
#include "IfGen.h"
#include "IifGen.h"
#include "LetGen.h"
#include "ValueGen.h"
#include "BlockGen.h"

IifGen::IifGen(CodeGen * cond_, CodeGen * thenValue_, CodeGen * elseValue_) : cond(cond_), thenValue(thenValue_), elseValue(elseValue_) {
	type = thenValue->type;
}

using namespace llvm;
llvm::Value * IifGen::generateCode(llvm::Module * m, llvm::Function * func, llvm::IRBuilder<>&builder)
{
	Type* ty = thenValue->type;

	auto & block = func->getEntryBlock();
	IRBuilder<> b(&block);
	auto* v=b.CreateAlloca(ty, nullptr, "iif");
	auto* p = new IfGen();
	p->condition = cond;
	p->thenBlock = new BlockGen();
	p->thenBlock->codes.push_back(new LetGen(new ValueGen(v), thenValue));
		
	if (elseValue) {
		p->elseBlock = new BlockGen();
		p->elseBlock->codes.push_back(new LetGen(new ValueGen(v), elseValue));
	}

	p->generate(m, func, builder);
	return v;
}
