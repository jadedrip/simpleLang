#pragma once
#include "CodeGen.h"

class BlockGen;
class IfGen : public CodeGen
{
public:
	CodeGen* condition;
	BlockGen* thenBlock = nullptr;
	BlockGen* elseBlock = nullptr;
protected:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
private:
	llvm::BasicBlock* _funcBlock = nullptr;
};

