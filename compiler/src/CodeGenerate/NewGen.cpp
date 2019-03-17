#include "stdafx.h"
#include "NewGen.h"
#include "modules.h"
#include "CallGen.h"
#include "LambdaGen.h"
#include "ValueGen.h"
#include "../Type/ClassInstanceType.h"
#include "llvm/Support/raw_os_ostream.h"

using namespace llvm;
inline Function* makeLink(Module*from, Module* to, StringRef name)
{
	auto * f=from->getFunction(name);
	assert(f);
	return Function::Create(f->getFunctionType(), GlobalValue::ExternalLinkage, name, to);
}

Function *createObject = nullptr;
Function *createArray = nullptr;
extern std::unique_ptr<Module> module;

inline void initCore()
{
	if (!createObject) {
		auto m = module.get();
		// createObject=CLangModule::getFunction("si", "createObject");
		Module* clib = CLangModule::loadLLFile("lib/si/core.ll");
		assert(clib);
		createObject = makeLink(clib, m, "createObject");
		createArray = makeLink(clib, m, "createArray");
	}
}

Function * NewGen::getCreateObject()
{
	initCore();
	return createObject;
}

Function * NewGen::getCreateArray()
{
	initCore();
	return createArray;
}

NewGen::NewGen(Type * type, CodeGen * c, CodeGen * len) : CodeGen(type), construstor(c), length(len) {}

Value * NewGen::generateCode(Module *m, Function *func, IRBuilder<>&builder)
{
	initCore();

	raw_os_ostream os(std::clog);
	std::clog << "new ";
 	//if (type->isStructTy()) {
	//	auto *p=dyn_cast<StructType>(type);
	//	bool zero=p->element_begin() == p->element_end();
	//	if (zero) {
	//		std::string u = p->getName();
	//		Function* createRefObject = clib->getFunction("createObject_" + u);
	//	}
	//}
	auto &c=builder.getContext();
	Constant* allocSize = ConstantExpr::getSizeOf(type);
	auto ITy = Type::getInt32Ty(c);
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

	Value* zero = ConstantInt::get(c, APInt(32, 0));

	// 通过默认构造函数来设置默认值，避免 This 指针找不到
	if(!defaultValues.empty()){
		auto type = FunctionType::get(Type::getVoidTy(c), pType, false);
		auto fu = Function::Create(type, Function::InternalLinkage, "", m);
		auto* basicBlock = BasicBlock::Create(c, "", fu);
		IRBuilder<> builder2(basicBlock);
		auto obj=fu->args().begin();

		// 先设置默认值
		for (auto i : defaultValues) {
			// auto *u=dynamic_cast<LambdaGen*>(i.second);
			// if(u) u->object
			Value* v = i.second->generate(m, fu, builder2);

			Value* idx = ConstantInt::get(c, APInt(32, i.first));
			// Type* pt = PointerType::get(v->getType(), 0);
			std::vector<Value*> args;
			args.push_back(zero);
			args.push_back(idx);
			Value* memberPointer = builder2.CreateInBoundsGEP(obj, args);
			//Value* x=builder.CreateBitOrPointerCast(memberPointer, pt);
			builder2.CreateStore(v, memberPointer);
		}
		builder2.CreateRetVoid();
		// 调用它
		builder.CreateCall(fu, value);
	}

	// 调用构造函数
	if (construstor) {
		auto* p=dynamic_cast<CallGen*>(construstor);
		p->object = new ValueGen(value);
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
