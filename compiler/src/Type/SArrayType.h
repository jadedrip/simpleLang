#pragma once
#include "AstType.h"
#include "Ast/AstList.h"

/*
	数组类型(数组是有固定大小的)
*/
class SArrayType : public AstType
{
public:
	SArrayType(AstType* type, AstNode* expr);
	AstType* memberType;
	AstNode* length;	// 长度，null 表示未知（通过初始化确定）
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);
	virtual CodeGen* malloc(AstContext* context);
public:
	virtual std::string uniqueName();
	virtual size_t hashCode();
};
