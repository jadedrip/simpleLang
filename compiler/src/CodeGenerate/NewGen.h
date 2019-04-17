#pragma once
#include "CodeGen.h"

class NewGen : public CodeGen
{
public:
	NewGen(llvm::Type* type = nullptr, CodeGen* c = nullptr, CodeGen* len = nullptr);
	CodeGen* construstor = nullptr;
	CodeGen* finalize = nullptr; // 析构函数
	CodeGen* length = nullptr;
	std::string name;
	std::map<int, CodeGen*> defaultValues;
public:
	static llvm::Function* getCreateObject();
	static llvm::Function* getCreateArray();
public:
	virtual llvm::Value* generateCode(const Generater& generater);
};