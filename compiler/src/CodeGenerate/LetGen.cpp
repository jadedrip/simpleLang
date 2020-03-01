#include "stdafx.h"
#include "LetGen.h"
#include "caster.h"
#include "ClassMemberGen.h"
#include "CallGen.h"
#include "IndexGen.h"

using namespace llvm;
llvm::Value * LetGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();
	// 如果有 set 函数
	auto *x=dynamic_cast<ClassMemberGen*>(_left);
	if (x && x->setFunction) {
		auto* o=x->object->generate(generater);
		auto* v = _right->generate(generater);
		return CallGen::call(builder, x->setFunction, o, v);
	}
	// 如果是复制到数组
	if (_toArray) {
		auto *p=dynamic_cast<IndexGen*>(_left);
		//CallGen::call(builder, "referenceIncrease", r);
		//std::clog << "Let right is " << toString(r->getType())
		//	<< " and left is " << toString(l->getType())
		//	<< std::endl;
		//return builder.CreateStore(r, l);
		auto *expr=p->expr->generate(generater);
		auto *index=p->index->generate(generater);
		auto* r = _right->generate(generater);
		return CallGen::call(builder, "arrayLet", expr, index, r);
	}

	llvm::Value* l = _left->generate(generater);
	assert(l->getType()->isPointerTy());
	auto* r = _right->generate(generater);

	auto valueType = l->getType()->getPointerElementType();
	r = load(builder, r);
	r = try_cast(builder, valueType, r);
	return builder.CreateStore(r, l);
}
