#include "stdafx.h"
#include "TupleSpreadGen.h"

using namespace llvm;

TupleSpreadGen::TupleSpreadGen(CodeGen* tuple) : _tuple(tuple) {
	tuple->valueType = ValueType::rvalue;
}

Value * TupleSpreadGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();

	auto *t = _tuple->generate(generater);
	assert(t->getType()->isStructTy());

	auto* ptr=builder.CreateAlloca(t->getType());
	builder.CreateStore(t, ptr);

	for (size_t i = 0; i < vars.size(); i++) {
		auto *v = vars[i]->generate(generater);
		Value* g = builder.CreateConstInBoundsGEP2_32(
			t->getType(), 
			ptr, 
			0, 
			(unsigned int)i
		);
		Value* gv = builder.CreateLoad(g->getType(), g);

		assert(v->getType()->isPointerTy());
		builder.CreateStore(gv, v);
	}

	return nullptr;
}
