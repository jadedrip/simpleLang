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
	auto &c = generater.context();

	Value* go = CallGen::call(builder, "CreateCoroutine", globles.size());
	 
	raw_os_ostream log(std::clog);
	size_t sz = 0;
	for (auto i : globles) {
		//auto *ptr=(GlobalVariable*)m->getOrInsertGlobal(i.first, i.second->type);
		auto *v=i->generate(generater);
		Value* func = nullptr;
		if (!i->type->isStructTy()) {
			// v = builder.CreateLoad(v, i);
			func = ConstantInt::get(c, APInt(-1, 64));
		}
		else {
			auto tp = i->type;
			auto *c=AstContext::findCompiledClassByLLVMType(tp);
			if (c->finalize) func = c->finalize->func;
			// 添加引用计数
			CallGen::call(builder, "referenceIncrease", v);
		}

		CallGen::call(builder, "SetCoroutineParams", go, sz, v, func);
	}
	auto funcPtr=_func->generate(generater);
	
	CallGen::call(builder, "si_CoroutineCreate", go, funcPtr);
	return go;
}
