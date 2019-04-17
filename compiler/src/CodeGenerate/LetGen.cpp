#include "stdafx.h"
#include "LetGen.h"
#include "caster.h"
#include "ClassMemberGen.h"
#include "CallGen.h"

using namespace llvm;
llvm::Value * LetGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();
	// 如果有 set 函数
	auto *x=dynamic_cast<ClassMemberGen*>(left);
	if (x && x->setFunction) {
		auto* o=x->object->generate(generater);
		auto* v = right->generate(generater);
		return CallGen::call(builder, x->setFunction, o, v);
	}

	llvm::Value* l = left->generate(generater);
	assert(l->getType()->isPointerTy());

	auto valueType = l->getType()->getPointerElementType();
	auto *r=right->generate(generater);
	r = load(builder, r);
	r = try_cast(builder, valueType, r);
	return builder.CreateStore(r, l);
}
