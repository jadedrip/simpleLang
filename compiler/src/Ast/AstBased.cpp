#include "stdafx.h"
#include "AstBased.h"
#include "AstContext.h"
#include "ClassContext.h"
#include "../Type/ClassInstanceType.h"
#include "../CodeGenerate/IfGen.h"
#include "../CodeGenerate/IntegerBinaryGen.h"
#include "../CodeGenerate/NullGen.h"
#include "../CodeGenerate/IsNullGen.h"
#include "../token.h"
#include "../utility.h"

using namespace llvm;
void AstBased::draw(std::ostream & os) {
	dotLable(os, name + "{}");
	for (auto i : block) {
		dotPointTo(os, i);
	}
}

CodeGen * AstBased::makeGen(AstContext * parent)
{
	auto*p = expr->makeGen(parent);
	auto* x = dyn_cast<StructType>(p->type);
	assert(x);

	auto *a = new IfGen();
	a->condition = new IsNullGen( p );  // p == null
	auto *context = new ClassContext(parent, p);
	a->thenBlock = makeCodeGenList(context, block);
	return a;
}
