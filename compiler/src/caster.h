#pragma once
#include <llvm/IR/IRBuilder.h>

llvm::Value* try_cast(llvm::IRBuilder<>& builder, llvm::Type* to_type, llvm::Value *value);

