#include "stdafx.h"
#include "GoGen.h"
#include "CallGen.h"
#include "modules.h"
#include "NewGen.h"
#include "CallGen.h"
#include "caster.h"

using namespace llvm;
GoGen::GoGen(CodeGen * func)
{
	_func = dynamic_cast<LambdaGen*>(func);
	assert(_func);
}

llvm::Value* GoGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	raw_os_ostream log(std::clog);
	for (auto i : globles) {
		//auto *ptr=(GlobalVariable*)m->getOrInsertGlobal(i.first, i.second->type);
		auto *v=i.second->generate(m, func, builder);
		if (!i.second->type->isStructTy())
			v = builder.CreateLoad(v, i.first);

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
			//  «¿‡
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

	llvm::Value* funcPtr=_func->generateCode(m, func, builder);

	auto *type=CLangModule::getStruct("si", "Coroutine");
	assert(type);
	Constant* allocSize = ConstantExpr::getSizeOf(type);

	auto *createObject = NewGen::getCreateObject();
	Value* coroutine = CallGen::call(builder, createObject, allocSize, (uintptr_t)type);

	auto* create=CLangModule::getFunction("si_CoroutineCreate");
	assert(create);
	CallGen::call(builder, create, coroutine, funcPtr);
	return coroutine;
}
