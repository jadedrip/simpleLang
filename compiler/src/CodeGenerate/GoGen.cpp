#include "stdafx.h"
#include "GoGen.h"
#include "CallGen.h"
#include "modules.h"
#include "NewGen.h"
#include "CallGen.h"

using namespace llvm;
GoGen::GoGen(CodeGen * func)
{
	_func = dynamic_cast<LambdaGen*>(func);
	assert(_func);
}

llvm::Value* GoGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
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
