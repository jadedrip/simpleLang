#include "stdafx.h"
#include "AstTuple.h"
#include "AstContext.h"
#include "utility.h"
#include "../AstContext.h"
#include "../Type/TupleType.h"
#include "../CodeGenerate/TupleGen.h"

void AstTuple::draw(std::ostream & os) {
	dotLable(os, "tuple");
	dotPointTo(os, elements);
}

CodeGen * AstTuple::makeGen(AstContext * parent)
{
	std::vector<llvm::Type*> types;
	TupleGen* gen = new TupleGen();

	for (auto i : elements) {
		CodeGen* p = i->makeGen(parent);
		gen->elements.push_back(p);
		types.push_back(p->type);
	}
	gen->type = TupleType::create(parent->context(), std::move(types));
	return gen;
}
