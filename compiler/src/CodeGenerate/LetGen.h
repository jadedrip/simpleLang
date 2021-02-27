#pragma once
#include "CodeGen.h"

class LetGen : public CodeGen
{
public:
	LetGen(CodeGen* left_, CodeGen* right_, bool toArray=false) 
		: _left(left_), _right(right_),_toArray(toArray) {
		_left->valueType = ValueType::lvalue;
		_right->valueType = ValueType::rvalue;
	}
protected:
	virtual llvm::Value* generateCode(const Generater& generater);
private:
	CodeGen* _left = nullptr;
	CodeGen* _right = nullptr;
	bool _toArray = false;
};