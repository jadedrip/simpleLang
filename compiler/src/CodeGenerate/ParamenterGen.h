#pragma once
#include "CodeGen.h"
#include <llvm/IR/ValueSymbolTable.h>

class ParamenterGen : public CodeGen
{
public:
	std::string name;
	llvm::Value* value = nullptr;

	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder) {
		if (!value) {
			auto* s=func->getValueSymbolTable();
			auto *v=s->lookup(name);
			auto* type = v->getType();
			if (!type->isPointerTy()) {	// 为了处理方便，数值变量处理为指针
				value = builder.CreateAlloca(v->getType());
				builder.CreateStore(v, value);
			} else {
				value = v;
			}
		}
		return value;
	}
};
