#pragma once
#include "CodeGen.h"

class ValueGen : public CodeGen
{
public:
	ValueGen(llvm::Value* v) : CodeGen(v->getType()) {
		this->value = v;
	}

	virtual llvm::Value* generateCode(const Generater& generater) {
		return value;
	}
};
