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
	virtual llvm::Value* generateCode(const Generater& generater);
private:
	llvm::BasicBlock* _funcBlock = nullptr;
};

