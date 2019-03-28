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

	auto *ty = dyn_cast<PointerType>(o->getType())->getElementType();
	return builder.CreateConstGEP2_32(ty, o, 0, index, name);
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
