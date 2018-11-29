#include "stdafx.h"
#include "TupleSpreadGen.h"

using namespace llvm;
Value * TupleSpreadGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<> &builder)
{
	auto *t = tuple->generate(m, func, builder);
	assert(t->getType()->isStructTy());

	auto* ptr=builder.CreateAlloca(t->getType());
	builder.CreateStore(t, ptr);

	for (size_t i = 0; i < vars.size(); i++) {
		auto *v = vars[i]->generate(m, func, builder);
		Value* g = builder.CreateConstInBoundsGEP2_32(t->getType(), ptr, 0, i);
		Value* gv = builder.CreateLoad(g);

		assert(v->getType()->isPointerTy());
		builder.CreateStore(gv, v);
	}

	return nullptr;
}
