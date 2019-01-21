#pragma once
#include "CodeGen.h"
class StringLiteGen : public CodeGen
{
public:
	StringLiteGen(llvm::LLVMContext&, const std::string& str);

	void append(StringLiteGen* gen);
	const std::string& str() const { return _str; }
public:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>& builder);
private:
	std::wstring _data;
	std::string _str;
	llvm::LLVMContext& _context;
};

