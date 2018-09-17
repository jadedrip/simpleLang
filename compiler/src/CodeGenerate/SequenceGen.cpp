#include "stdafx.h"
#include "SequenceGen.h"
#include "caster.h"

using namespace llvm;
Value * SequenceGen::generateCode(Module * m, Function * func, IRBuilder<>&builder) {
	// 先实现普通数值
	auto &context = builder.getContext();
	auto ITy = Type::getInt32Ty(context);
	auto sz=ConstantInt::getSigned(ITy, values.size());
	auto p=builder.CreateAlloca(type, sz, "sequence");
	auto idx = 0;
	for (auto i : values) {
		auto v=i->generate(m, func, builder);
		auto x = builder.CreateGEP(p, ConstantInt::getSigned(ITy, idx++));
		
		if (v->getType()->isPointerTy()) {
			v = builder.CreateLoad(v);
		}
		v = try_cast(builder, type, v);
		builder.CreateStore(v, x);
	}
	return p;
}
