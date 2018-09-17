#pragma once
#include "CodeGen.h"

class BlockGen : public CodeGen {
public:
	std::string name;
	std::vector< CodeGen*> codes;
	llvm::BasicBlock* next = nullptr;
	llvm::BasicBlock* block = nullptr;		// 生成的块
	bool br = true;
public:
	void add(CodeGen* gen) { codes.push_back(gen); }
public:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
};
