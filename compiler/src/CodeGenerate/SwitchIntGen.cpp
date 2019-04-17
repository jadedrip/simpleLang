#include "stdafx.h"
#include "SwitchIntGen.h"

using namespace llvm;
llvm::Value * SwitchIntGen::generateCode(const Generater& generater)
{
	auto func = generater.func;
	auto& builder = generater.builder();

	// 比较值
	Value *v = expression->generate(generater);
	v = load(builder, v);
	auto *tp = v->getType();
	unsigned int all = 0;

	CaseGen* d= nullptr;	// default
	for (auto i : cases) {
		auto c = (unsigned int)i->conditions.size();
		all += c == 0 ? 1 : c;

		if (i->conditions.empty()) {	 
			d = i;
		}
	}

	auto &context=builder.getContext();
	BasicBlock *end = BasicBlock::Create(context, "SwitchEnd", func);
	BasicBlock *dest;
	if (d) { // 如果有默认值块
		d->codes->next = end;
		auto *x=d->codes->generate(generater);
		dest = dyn_cast_or_null<BasicBlock>(x);
	}
	else
		dest = end;

	Generater g = { generater.module, func, &builder, dest };

	auto p = builder.CreateSwitch(v, dest, all);
	for (auto i : cases) {
		i->codes->next = end;
		i->codes->generate(g);
		auto *cs=dyn_cast_or_null<BlockGen>(i->codes);
		BasicBlock *b = dyn_cast_or_null<BasicBlock>(cs->block);
		
		for (auto o : i->conditions) {
			v = o->generate(g);
			v = load(builder, v);
			v = builder.CreateTruncOrBitCast(v, tp);

			auto x = dyn_cast_or_null<ConstantInt>(v);
			if (!x) throw std::runtime_error("Case 条件的类型错误");
			p->addCase(x, b);
		}
	}

	builder.SetInsertPoint(end);
	return nullptr;
}
