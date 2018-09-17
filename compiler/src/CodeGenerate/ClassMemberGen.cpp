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

	Value* idx=ConstantInt::get(builder.getContext(), APInt(index,32));
	return builder.CreateGEP( o, idx, name );
}
