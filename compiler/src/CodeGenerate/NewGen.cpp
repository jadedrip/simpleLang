#include "stdafx.h"
#include "NewGen.h"
#include "modules.h"
#include "CallGen.h"
#include "../Type/ClassInstanceType.h"
#include "llvm/Support/raw_os_ostream.h"

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
		Module* clib = CLangModule::loadLLFile("lib/core.ll");
		assert(clib);
		createObject = makeLink(clib, m, "createObject");
		createArray = makeLink(clib, m, "createArray");
	}
	llvm::raw_os_ostream os(std::clog);
	std::clog << "new ";
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

	Value* zero = ConstantInt::get(builder.getContext(), APInt(32, 0));
	// 先设置默认值
	for (auto i : defaultValues) {
		Value* v= i.second->generate(m, func, builder);

		Value* idx = ConstantInt::get(builder.getContext(), APInt(32, i.first));
		// Type* pt = PointerType::get(v->getType(), 0);
		std::vector<Value*> args;
		args.push_back(zero);
		args.push_back(idx);
		Value* memberPointer = builder.CreateInBoundsGEP(value, args);
		//Value* x=builder.CreateBitOrPointerCast(memberPointer, pt);
		builder.CreateStore(v, memberPointer);
	}

	// 调用构造函数
	if (construstor) {
		auto* p=dynamic_cast<CallGen*>(construstor);
		p->params[0]->value = value;
		construstor->generate(m, func, builder);
	}
	//auto *c = _type->constructor;
	//if (c) {
	//	std::vector<Value*> a;
	//	a.push_back(v);
	//	c->generateCall(builder, a);
	//}

	std::string n = type->getStructName();
	n[0] = tolower(n[0]);
	value->setName(n);
	value->print(os);
	os.flush();
	std::clog << std::endl;
	return value;
}
