#include "stdafx.h"
#include "GoGen.h"
#include "CallGen.h"
#include "modules.h"

GoGen::GoGen(CodeGen * func)
{
	auto _func = dynamic_cast<LambdaGen*>(func);
	assert(_func);
}

llvm::Value* GoGen::generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder)
{
	llvm::Value* funcPtr=_func->generateCode(m, func, builder);

	auto* p=CLangModule::getFunction("si", "makeGo");
	assert(p);
	return CallGen::call(builder, p, funcPtr);
}
