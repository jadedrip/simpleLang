#pragma once
#include "AstType.h"

class AutoType : public AstType {
public:
	AutoType() : AstType(AutoTyId){
		name = "auto";				// 命名
	}

	static bool isAuto(AstType* type) { return !type || dynamic_cast<AutoType*>(type); }
	void setDeductive(llvm::Type* type) { _deductive = type;  }
public:
	virtual llvm::Type* llvmType(llvm::LLVMContext& context) {
		if (!_deductive) throw std::runtime_error("Unknown auto type.");
		return _deductive;
	}
protected:
	llvm::Type* _deductive = nullptr;
};
