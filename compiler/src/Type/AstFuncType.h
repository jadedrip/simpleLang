#pragma once
#include <vector>
#include <llvm/IR/Function.h>
#include "AstType.h"

class AstFuncType : public AstType {
public:
	virtual llvm::Type* llvmType(llvm::LLVMContext& context)
	{
		using namespace llvm;
		if (_ft) return _ft;
		std::vector<llvm::Type*> types;
		for (auto i : attrs) {
			auto* tp = i->llvmType(context);
			types.push_back(tp);
		}
		llvm::Type* r = ret ? ret->llvmType(context) : llvm::Type::getVoidTy(context);

		_ft = FunctionType::get(r, types, false);
		return _ft;
	}
public:
	std::vector<AstType*> attrs;
	// ·µ»ØÖµ
	AstType* ret = nullptr;
private:
	llvm::FunctionType *_ft = nullptr;
};

