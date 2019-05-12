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
Function *referenceIncrease = nullptr;
Function* freeObject = nullptr;
extern std::unique_ptr<Module> module;

inline void initCore()
{
	if (!createObject) {
		auto m = module.get();
		// createObject=CLangModule::getFunction("si", "createObject");
		Module* clib = CLangModule::loadLLFile("clib/si.ll");
		assert(clib);
		createObject = makeLink(clib, m, "createObject");
		createArray = makeLink(clib, m, "createArray");
		referenceIncrease = makeLink(clib, m, "referenceIncrease");
		freeObject = makeLink(clib, m, "freeObject");
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

Value * NewGen::generateCode(const Generater& generater)
{
	auto& builder = generater.builder();

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
	auto ITy = Type::getInt32Ty(c);
	// 数组保存指针
	if (length)
		type = PointerType::get(type, 0);
	// 类型 ID
	Value* typeId=ConstantInt::get(ITy, (uintptr_t) type);
	Constant* allocSize = ConstantExpr::getSizeOf(type);
	auto* pType = PointerType::get(type, 0);
	if (this->escape) {
		// 如果是逃逸变量，那么通过 create 创建
		if (length) {	  // 是数组, 保存指针
			auto* v = length->generate(generater);
			value = CallGen::call(builder, createArray, allocSize, typeId, v);
		} else {
			value = CallGen::call(builder, createObject, allocSize, typeId);
		}
		value = builder.CreateBitCast(value, pType);
		//raw_os_ostream os(std::clog);
		//generater.deallocate->print(os);
		//os.flush();
		// 同时在销毁块调用销毁
		IRBuilder<> bd(generater.deallocate);
		Value* v = nullptr;
		if (finalize) {
			Generater g = generater;
			g._builder = &bd;
			v = finalize->generate(g);
			//assert(v->getType()->isFunctionTy());
		}
		CallGen::call(bd, freeObject, value, v);
	} else {
		// 非逃逸变量创建在 alloc 块里，避免在循环里导致多次创建 
		auto* lv = length ? length->generate(generater) : nullptr;
		auto &allocBlock = generater.func->getBasicBlockList().front();
		IRBuilder<> allocBuilder(&allocBlock);
		value = allocBuilder.CreateAlloca(type, lv, name);

		// 同时在销毁块调用析构
		if (finalize) {
			Generater g = generater;
			IRBuilder<> bd(generater.deallocate);
			g._builder = &bd;
			// TODO: 构造函数
			llvm::Value* v=finalize->generate(g);
			// assert(v->getType()->isFunctionTy());
			CallGen::call(bd, dyn_cast<Function>(v), value);
		}
	}

	Value* zero = ConstantInt::get(c, APInt(32, 0));

	// 通过默认构造函数来设置默认值，避免 This 指针找不到
	if(!length && !defaultValues.empty()){
		auto type = FunctionType::get(Type::getVoidTy(c), pType, false);
		auto fu = Function::Create(type, Function::InternalLinkage, "", generater.module);
		auto* basicBlock = BasicBlock::Create(c, "", fu);
		IRBuilder<> builder2(basicBlock);
		auto obj=fu->args().begin();

		// 先设置默认值
		for (auto i : defaultValues) {
			// auto *u=dynamic_cast<LambdaGen*>(i.second);
			// if(u) u->object
			Value* v = i.second->generate(generater);

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
		construstor->generate(generater);
	}

	//auto *c = _type->constructor;
	//if (c) {
	//	std::vector<Value*> a;
	//	a.push_back(v);
	//	c->generateCall(builder, a);
	//}

	//std::string n = type->getStructName();
	//n[0] = tolower(n[0]);
	//value->setName(n);
	//value->print(os);
	//os.flush();
	//std::clog << std::endl;
	return value;
}
