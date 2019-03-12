#include "stdafx.h"
#include "ClassMemberGen.h"

using namespace llvm;
Value * ClassMemberGen::generateCode(Module *m, Function *func, IRBuilder<>&builder)
{
	Value* o = object->generate(m, func, builder);
	if (getFunction) {
		std::vector<Value*> params;
		params.push_back(o);
		return builder.CreateCall(getFunction, params);
	}

	Value* zero = ConstantInt::get(builder.getContext(), APInt(32, 0));
	Value* idx=ConstantInt::get(builder.getContext(), APInt(32, index));
	//auto ty = type;
	//if (type->isIntegerTy() || type->isFloatingPointTy()) {
	//	ty = PointerType::get(type,0);
	//}
	std::vector<Value*> args;
	args.push_back(zero);
	args.push_back(idx);
	Value* v=builder.CreateInBoundsGEP( o, args, name );
	//return builder.CreateBitOrPointerCast(v, ty);
	return v;
}

ClassMemberGen * ClassMemberGen::clone(CodeGen* thisGen)
{
	auto *p = new ClassMemberGen(thisGen, index);
	p->name = name;
	p->type = type;
	p->isProtected = isProtected;
	p->setFunction = setFunction;
	p->getFunction = getFunction;
	return p;
}
