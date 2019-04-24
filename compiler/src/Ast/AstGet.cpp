#include "stdafx.h"
#include "AstGet.h"
#include "AstContext.h"
#include "AstGetClass.h"
#include "CodeGenerate/CodeGen.h"
#include "modules.h"

CodeGen * AstGet::makeGen(AstContext * parent)
{	

	auto* p=parent->findSymbolValue(name);
	if (!p) throw std::runtime_error("找不到变量:" + name);
	//auto* c=dynamic_cast<AstGetClass*>(p->type);
	//if (c) {
	//	auto *x=parent->findClass(c->name);
	//	x->getInstance();
	//}
	return p;
}

void AstGet::draw(std::ostream & os) {
	dotLable(os, "Get " +(right ? name : "const " + name));
}
