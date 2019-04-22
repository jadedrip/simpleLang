#include "stdafx.h"
#include "NullGen.h"
#include "../Type/AstType.h"

using namespace llvm;
NullGen::NullGen(llvm::Type* ty) {
	type = ty;
}

llvm::Value* NullGen::generateCode(const Generater& generater) {
	auto *p=type;
	auto *o=p->getPointerTo();
	return llvm::ConstantPointerNull::get(o);
}
