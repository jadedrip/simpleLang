#include "stdafx.h"
#include "NullGen.h"
#include "../Type/AstType.h"

using namespace llvm;
NullGen::NullGen(llvm::Type* ty) {
	type = ty;
}

llvm::Value* NullGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder) {
	auto *p=type;
	auto *o=p->getPointerTo();
	return llvm::ConstantPointerNull::get(o);
}
