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
llvm::Value * IifGen::generateCode(const Generater& generater)
{
	auto func = generater.func;

	auto* v = generater.alloc(thenValue->type, "iif");
	
	auto* p = new IfGen();
	p->condition = cond;
	p->thenBlock = new BlockGen();
	p->thenBlock->codes.push_back(new LetGen(new ValueGen(v), thenValue));
		
	if (elseValue) {
		p->elseBlock = new BlockGen();
		p->elseBlock->codes.push_back(new LetGen(new ValueGen(v), elseValue));
	}

	p->generate(generater);
	return v;
}
