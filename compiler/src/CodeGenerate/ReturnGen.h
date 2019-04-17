#pragma once
#include "CodeGen.h"
#include "TupleGen.h"

class ReturnGen : public CodeGen {
public:
	std::vector< CodeGen* > returnValues;

	virtual llvm::Value* generateCode(const Generater& generater);
};
