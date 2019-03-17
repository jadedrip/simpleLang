#include "stdafx.h"
#include "caster.h"
#include "ReturnGen.h"
#include "../Type/ClassInstanceType.h"

llvm::Value * ReturnGen::generateCode(llvm::Module * m, llvm::Function * func, llvm::IRBuilder<>& builder) {
	if (returnValues.empty()) {
		return builder.CreateRetVoid();
	}
	else if (returnValues.size() == 1) {
		auto* p = returnValues.front();
		llvm::Value* v = p->generate(m, func, builder);
		if (!p->type->isStructTy())
			v = load(builder, v);
		auto rt=func->getReturnType();
		return builder.CreateRet(try_cast(builder, rt, v));
	}
	else {
		auto *p = new TupleGen();
		for (auto &i : returnValues) {
			p->elements.push_back(i);
		}

		llvm::Value* v = p->generate(m, func, builder);
		v=builder.CreateLoad(v, "return");
		return builder.CreateRet(v);	// 返回 Tuple 的对象
	}
}
