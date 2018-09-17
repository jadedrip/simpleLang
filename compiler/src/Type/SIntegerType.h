#pragma once
#include "AstType.h"

class SIntegerType : public AstType
{
public:
	static SIntegerType* get(int bitWidth, bool isUnsigned=false);
public:
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);

	virtual std::string uniqueName();

	int bitWidth;
	bool isUnsigned = false;
private:
	SIntegerType(int bitWidth, bool isUnsigned);
};

