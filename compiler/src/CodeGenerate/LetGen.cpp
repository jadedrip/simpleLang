#include "stdafx.h"
#include "LetGen.h"
#include "caster.h"
#include "ClassMemberGen.h"
#include "CallGen.h"

using namespace llvm;
llvm::Value * LetGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	// 如果有 set 函数
	auto *x=dynamic_cast<ClassMemberGen*>(left);
	if (x && x->setFunction) {
		auto* o=x->object->generate(m, func, builder);
		auto* v = right->generate(m, func, builder);
		return CallGen::call(builder, x->setFunction, o, v);
	}

	llvm::Value* l = left->generate(m, func, builder);
	assert(l->getType()->isPointerTy());

	auto valueType = l->getType()->getPointerElementType();
	right->hopeType = valueType;
	auto *r=right->generate(m, func, builder);
	r = load(builder, r);
	r = try_cast(builder, valueType, r);
	return builder.CreateStore(r, l);
}
