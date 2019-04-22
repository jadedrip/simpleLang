#pragma once
#include "CodeGen.h"

class BlockGen : public CodeGen {
public:
	std::string name;
	std::vector< CodeGen*> codes;
	llvm::BasicBlock* block = nullptr;		// 生成的块
	// 块执行完后，跳转
	llvm::BasicBlock* next = nullptr;
public:
	void add(CodeGen* gen) { codes.push_back(gen); }
public:
	virtual llvm::Value* generateCode(const Generater& generater);
};
