#pragma once
#include "AstType.h"
#include "AstContext.h"

// 整数型枚举变量
class EnumType : public AstType
{
public:
	std::map<std::string, CodeGen* > enums;
public:
	virtual std::string uniqueName();
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);
	virtual AstContext* makeContext(AstContext *context, CodeGen* codeGen);	
};
