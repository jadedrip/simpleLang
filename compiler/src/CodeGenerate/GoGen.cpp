#include "stdafx.h"
#include "GoGen.h"
#include "CallGen.h"
#include "modules.h"
#include "NewGen.h"
#include "CallGen.h"
#include "caster.h"
#include "../AstContext.h"
#include "../Type/ClassInstanceType.h"

using namespace std;
using namespace llvm;
GoGen::GoGen(CodeGen * func)
{
	_func = dynamic_cast<LambdaGen*>(func);
	assert(_func);
}

llvm::Value* GoGen::generateCode(const Generater& generater)
{
	auto* m = generater.module;
	auto &builder = generater.builder();

	vector<Value*> structs;
	raw_os_ostream log(std::clog);
	for (auto i : globles) {
		//auto *ptr=(GlobalVariable*)m->getOrInsertGlobal(i.first, i.second->type);
		auto *v=i.second->generate(generater);
		if (!i.second->type->isStructTy())
			v = builder.CreateLoad(v, i.first);
		else {
			// 添加引用计数
			auto* i = CLangModule::getFunction("referenceIncrease");
			assert(i);
			CallGen::call(builder, i, v);
			structs.push_back(v);
		}

		auto tp = i.second->type;
		bool st = tp->isStructTy();
		if (st) {
			tp = PointerType::get(tp, 0);
		}

		GlobalVariable* ptr = new GlobalVariable(/*Module=*/*m,
			/*Type=*/tp,
			/*isConstant=*/false,
			/*Linkage=*/GlobalValue::CommonLinkage,
			/*Initializer=*/0, // has initializer, specified below
			/*Name=*/i.first);
		
		if (st) {
			// 是类
			ConstantPointerNull* n = ConstantPointerNull::get( dyn_cast<PointerType>(tp));
			ptr->setInitializer(n);
			// ptr->setAlignment(8);
		} else {
			auto * n = ConstantInt::get(i.second->type, 0L);
			ptr->setInitializer(n);
		}
		// Global Variable Definitions
		// auto *x=builder.CreateGEP(v, 0);
		auto *x=builder.CreateStore(v, ptr);

		//llvm::raw_os_ostream os(std::clog);
		//os << "GlobelWrapValue " << i.first << " :";
		//x->print(os);
		//os << "\r\n";
		//os.flush();
	}

	// 在函数最后写入析构代码
	llvm::Value* funcPtr=_func->generateCode(generater);
	Function* f = dyn_cast<Function>(funcPtr);
	auto &allocBlock=f->back();
	assert(allocBlock.getName() == "dealloc");

	IRBuilder<> db(&allocBlock);
	for (auto i : structs) {
		auto ty = dyn_cast<StructType>(i->getType());
		auto *c=AstContext::findCompiledClassByLLVMType(ty);
		assert(c);
		Value* fz = nullptr;
		if (c->finalize) {
			fz = c->finalize->func;
		}
		CallGen::call(db, "freeObject", i, fz);
	}

	auto *type=CLangModule::getStruct("si", "Coroutine");
	assert(type);
	Constant* allocSize = ConstantExpr::getSizeOf(type);

	auto *createObject = NewGen::getCreateObject();
	Value* coroutine = CallGen::call(builder, createObject, allocSize, (uintptr_t)type);

	CallGen::call(builder, "si_CoroutineCreate", coroutine, funcPtr);
	return coroutine;
}
