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
	// assert(t);
	this->_value = value;
	this->type = t;
}

llvm::Value * DefGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	isClass = type ? type->isStructTy() : true;
	bool isSeq = arraySize > 1;
		
	LLVMContext& context = builder.getContext();
	auto & block = func->getEntryBlock();

	IRBuilder<> b(&block);

	if (_value) {
		auto *x=dynamic_cast<NewGen*>(_value);
		if (x) {
			x->name = name;
		} 
		llvm::Value* v = _value->generate(m, func, builder);

		if (isClass || isSeq) {
			if (!x && this->escape) {
				// 如果变量会逃逸, 赋值的时候添加引用计数
				auto *i=CLangModule::getFunction("referenceIncrease");
				assert(i);
				CallGen::call(builder, i, v);
			};
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

