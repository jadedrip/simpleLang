#include "stdafx.h"
#include "AstNew.h"
#include "utility.h"
#include "AstClass.h"
#include "AstLet.h"
#include "AstPackage.h"
#include "AstGetClass.h"
#include "FunctionInstance.h"
#include "../AstContext.h"
#include "../CodeGenerate/NewGen.h"
#include "../CodeGenerate/GenList.h"
#include "../CodeGenerate/BlockGen.h"
#include "../Type/ClassInstanceType.h"
#include "AstGetClass.h"

void AstNew::draw(std::ostream & os)
{
	std::string n = nodeId;
	dotLable(os, "new " + name, "box");
}

CodeGen * AstNew::makeGen(AstContext * parent)
{
	assert(type);
	AstClass* cls = parent->findClass(type->name);

    // 通过逃逸分析，判断对象是否要建立在堆栈上
	std::vector<std::pair<std::string, CodeGen*>> args;
	for (auto i : blocks) {
		auto* c = i->makeGen(parent);
		if (dynamic_cast<AstLet*>(i))
			args.push_back(std::make_pair(i->name, c));
		else
			args.push_back(std::make_pair(std::string(), c));
	}
	auto *o=dynamic_cast<AstGetClass*>(type);
	CodeGen* a = cls->makeNew(parent, args, (o ? &(o->templateVars): nullptr));
	if (!a)
		throw std::runtime_error("Can't make class " + cls->name);
	if (!name.empty())
		parent->setSymbolValue(name, a);
	return a;
}

