#pragma once
#include "CodeGen.h"
class StringLiteGen : public CodeGen
{
public:
	StringLiteGen(AstContext*, const std::string& str);

	void append(StringLiteGen* gen);
	const std::string& str() const { return _str; }
public:
	virtual llvm::Value* generateCode(const Generater& generater);
private:
	std::wstring _data;
	std::string _str;
};

