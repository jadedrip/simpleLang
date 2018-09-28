#include "stdafx.h"
#include "DefGen.h"
#include "NewGen.h"
#include "StringLiteGen.h"
#include "CallGen.h"
#include "caster.h"
#include "../modules.h"
#include "utility.h"

using namespace llvm;
DefGen::DefGen(const std::string & n, Type * t, CodeGen* value, int s) : name(n), arraySize(s) {
	assert(t);
	this->_value = value;
	this->type = t;
}

llvm::Value * DefGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	assert(type);
	isClass = type->isStructTy();
	bool isSeq = arraySize > 1;
		
	LLVMContext& context = builder.getContext();
	auto & block = func->getEntryBlock();

	IRBuilder<> b(&block);

	if (_value) {
		llvm::Value* v = _value->generate(m, func, builder);

		if (isClass) {
			return v;
		}
		else if (isSeq) { 
			return v;
		}else{
			v = load(builder, v);
			v = try_cast(builder, type, v);
		}

		// 如果数字，转为指针
		value = b.CreateAlloca(type, nullptr, name);
		builder.CreateStore(v, value);
	} else if (!isClass) {
		value = b.CreateAlloca(type, nullptr, name);
		auto defaultValue = getDefaultValue(type);
		if (defaultValue)
			builder.CreateStore(defaultValue, value);
	}
	return value;
}

