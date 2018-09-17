#include "stdafx.h"
#include "NewGen.h"
#include "modules.h"
#include "CallGen.h"
#include "../Type/ClassInstanceType.h"

using namespace llvm;
inline llvm::Function* makeLink(llvm::Module*from, llvm::Module* to, llvm::StringRef name)
{
	auto * f=from->getFunction(name);
	assert(f);
	return Function::Create(f->getFunctionType(), GlobalValue::ExternalLinkage, name, to);
}

Function *createObject = nullptr;
Function *createArray = nullptr;
NewGen::NewGen(llvm::Type * type, CodeGen * c, CodeGen * len) : CodeGen(type), construstor(c), length(len) {}
llvm::Value * NewGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	if (!createObject) {
		Module* clib = CLangModule::loadLLFile("lib/core");
		assert(clib);
		createObject = makeLink(clib, m, "createObject");
		createArray = makeLink(clib, m, "createArray");
	}

	//if (type->isStructTy()) {
	//	auto *p=dyn_cast<StructType>(type);
	//	bool zero=p->element_begin() == p->element_end();
	//	if (zero) {
	//		std::string u = p->getName();
	//		Function* createRefObject = clib->getFunction("createObject_" + u);
	//	}
	//}

	Constant* allocSize = ConstantExpr::getSizeOf(type);
	auto ITy = Type::getInt32Ty(m->getContext());
	Value* typeId=ConstantInt::get(ITy, (uintptr_t) type);

	if (length) {	  // 是数组
		auto *v=length->generate(m, func, builder);
		value=CallGen::call(builder, createArray, allocSize, typeId, v);
	}
	else {
		value=CallGen::call(builder, createObject, allocSize, typeId);
	}
	auto *pType = PointerType::get(type, 0);
	value = builder.CreateBitCast(value, pType);

	// 调用构造函数
	if (construstor) construstor->generate(m, func, builder);

	//auto *c = _type->constructor;
	//if (c) {
	//	std::vector<Value*> a;
	//	a.push_back(v);
	//	c->generateCall(builder, a);
	//}

	std::string n = type->getStructName();
	n[0] = tolower(n[0]);
	value->setName(n);
	return value;
}
