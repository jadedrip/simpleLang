#include "stdafx.h"
#include "AstGo.h"
#include "AstFunction.h"
#include "AstContext.h"
#include "AstList.h"
#include "AstImport.h"
#include "CodeGenerate/GoGen.h"
#include "modules.h"

AstGo::AstGo(AstNode* node) : _node(node)
{
	assert(node);
}

CodeGen * AstGo::makeGen(AstContext * parent)
{
	auto&c = parent->context();
	auto* func = dynamic_cast<AstFunction*>(_node);
	// 如果不是函数，说明是函数调用，包装为匿名函数
	if (!func) {
		func = new AstFunction();
		func->funcType = AstFunction::Lambda;
		func->block.push_back(_node);
	}

	auto* x = func->makeGen(parent);
	auto* p = new GoGen(x);
	// auto* g = AstImport::loadClass("si", "Coroutine");
	p->type = CLangModule::getStruct("si", "Coroutine");
	return p;
}
