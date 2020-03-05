#pragma once
#include "CodeGen.h"

/*
	元组的自动解构代码生成器
*/
class TupleSpreadGen : public CodeGen
{
public:
	TupleSpreadGen(CodeGen* tuple);
	std::vector<CodeGen*> vars;
private:
	CodeGen* _tuple;
protected:
	virtual llvm::Value* generateCode(const Generater& generater);
};
