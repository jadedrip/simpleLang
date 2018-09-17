#include "stdafx.h"
#include "AstLet.h"
#include "AstContext.h"
#include "AstCall.h"
#include "utility.h"
#include "AstIf.h"
#include "../Type/AutoType.h"
#include "CodeGenerate/LetGen.h"
#include <llvm/IR/LLVMContext.h>

CodeGen * AstLet::makeGen(AstContext * parent)
{
	auto *v = parent->findSymbolValue(name);
	if (!v) throw std::runtime_error("Can't find var:" + name);

	auto p = right->makeGen(parent);
	if (!p)
		throw std::runtime_error("Can't let "+name);

	if (!v->type) {	// 左值需要推断	
		v->type=p->type;
	}

	auto *l = parent->findSymbolValue(name, true);
	return new LetGen(l, p);
}

void AstLet::draw(std::ostream & os)
{
	dotLable(os, name + "=");
	dotPointTo(os, right);
}
