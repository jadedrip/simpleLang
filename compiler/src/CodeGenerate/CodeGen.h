#pragma once
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

class CodeGen {
public:
	CodeGen(llvm::Type* t = nullptr);
	llvm::Type* type;
	llvm::Type* hopeType = nullptr; // 期望返回的类型(帮助部分节点优化）
	llvm::Value* value = nullptr;
	llvm::Value* generate(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder);
	// enum ValueType { ivalue = 0, lvalue, rvalue }; // 无所谓，左值，右值
	// ValueType valueType = ivalue;
	llvm::Value* load(llvm::IRBuilder<>& builder, llvm::Value* v);
protected:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&) = 0;
};

