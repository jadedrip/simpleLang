#include "stdafx.h"
#include "AstIndex.h"
#include "utility.h"
#include "CodeGenerate/IndexGen.h"

CodeGen * AstIndex::makeGen(AstContext * parent)
{
	IndexGen* p = new IndexGen();
	p->expr = expr->makeGen(parent);
	p->index = index->makeGen(parent);

	auto x = p->expr->type;
	assert(x->isPointerTy());
	p->type = x->getPointerElementType();
	return p;
}
