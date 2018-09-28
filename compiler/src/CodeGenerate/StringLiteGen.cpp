#include "stdafx.h"
#include "StringLiteGen.h"
#include "CallGen.h"
#include "../modules.h"
#include <Windows.h>

using namespace llvm;
StringLiteGen::StringLiteGen(llvm::LLVMContext& c, const std::string & s) : _str(s), _context(c)
{
	type = CLangModule::getStruct("si", "String");
}
void StringLiteGen::append(StringLiteGen * g)
{
	_str += g->_str;
	type = CLangModule::getStruct("si", "String");
}

llvm::Value * StringLiteGen::generateCode(llvm::Module * m, llvm::Function * func, llvm::IRBuilder<>& builder)
{
	auto i8ptr = IntegerType::getInt8PtrTy(m->getContext());
	
	if (hopeType && hopeType == i8ptr) {
		return builder.CreateGlobalStringPtr(_str);
	}
	// auto i16=llvm::IntegerType::get(m->getContext(), 16);
	// auto arrayTy=ArrayType::get(i16, str.size());
	// new GlobalVariable(*m, arr, true, Link  )

	auto* s = CLangModule::getStruct("si", "String");
	auto* createObject = CLangModule::getFunction("createObject");

	Constant* allocSize = ConstantExpr::getSizeOf(s);
	auto * v=CallGen::call(builder, createObject, allocSize, 0);
	auto * ps = PointerType::get(s, 0);
	auto * p=builder.CreateBitOrPointerCast(v, ps);

	//auto ty16 = Type::getInt16Ty(m->getContext());
	//auto ty32 = IntegerType::getInt32Ty(m->getContext());
	//auto ty64 = Type::getInt64Ty(m->getContext());
	//std::vector<Value*> args0;
	//auto* ty=allocSize->getType();
	//int o=ty->getIntegerBitWidth();
	//args0.push_back(allocSize);
	//args0.push_back(ConstantInt::get(ty32, 0));
	//auto* v = builder.CreateCall(createObject, args0, "createObject");

	auto* init = CLangModule::getFunction("si_String_init");
	auto* data = builder.CreateGlobalStringPtr(_str);
	CallGen::call(builder, init, p, CP_UTF8, data, _str.size(), p->getType());
	return p;
}
