#pragma once
#include "CodeGen.h"

class TypeOnlyGen : public CodeGen {
public:
	virtual llvm::Value* generateCode(const Generater& generater) { return nullptr; };

	TypeOnlyGen(llvm::Type* type) {
		this->type = type;
	}
};