#pragma once
#include <llvm/IR/LLVMContext.h>
#include "CodeGen.h"

/// �з��Ÿ�����
class FloatPointerGen : public CodeGen
{
public:
	FloatPointerGen(llvm::LLVMContext& c, double v, bool is);
	double getDouble() const { return _value; }
protected:
	llvm::Value* generateCode(const Generater& generater);
private:
	double _value;
	bool _isDouble;
};