#pragma once
#include "CodeGen.h"

/* 仅用于静态推导 */
class StaticTypeGen : public CodeGen {
public:
	virtual llvm::Value* generateCode(const Generater& generater) { return nullptr; };

	StaticTypeGen(bool isTrue) {
		this->type = nullptr;
		this->isTrue = isTrue;
	}
	bool isTrue;
};