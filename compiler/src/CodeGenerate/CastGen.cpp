#include "stdafx.h"
#include "CastGen.h"
#include "utility.h"
#include "caster.h"

CastGen::CastGen(llvm::Type * t, CodeGen * v) {
	type = t;
	value = v;
}

llvm::Value * CastGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();

	llvm::Type *t=type;
	auto *v = value->generate(generater);
	return try_cast(builder, t, v);
}
