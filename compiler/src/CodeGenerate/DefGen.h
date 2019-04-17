
#pragma once
#include "CodeGen.h"

class DefGen : public CodeGen {
public:
	DefGen(const std::string& n, llvm::Type* t, CodeGen* value=nullptr, int arraySize=1);
	std::string name;

	virtual llvm::Value* generateCode(const Generater& generater);
private:
	CodeGen* _value = nullptr;
	bool isClass = false;
	int arraySize;
};