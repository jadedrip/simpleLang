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
	virtual CodeGen* run(GenContent& content);
private:
	llvm::BasicBlock* _funcBlock = nullptr;
};

