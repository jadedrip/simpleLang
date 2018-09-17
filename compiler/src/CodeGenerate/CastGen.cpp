#include "stdafx.h"
#include "CastGen.h"
#include "utility.h"
#include "caster.h"

CastGen::CastGen(llvm::Type * t, CodeGen * v) {
	type = t;
	value = v;
}

llvm::Value * CastGen::generateCode(llvm::Module * m, llvm::Function * func, llvm::IRBuilder<>&builder)
{
	llvm::Type *t=type;
	auto *v = value->generate(m, func, builder);
	return try_cast(builder, t, v);
}
