#include "stdafx.h"
#include "AstGo.h"
#include "AstFunction.h"
#include "AstContext.h"
#include "AstLet.h"
#include "AstList.h"
#include "AstImport.h"
#include "AstReturn.h"
#include "AstConstant.h"
#include "../Type/LLVMType.h"
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
	// go 的匿名返回 void*, 我们改造一下
	AstLet* let = new AstLet();
	let->type = LLVMType::getVoidPtr(parent->context());
	func->rets.push_back(let);
	auto * r = new AstReturn();
	auto *zero = new AstConstant("0");
	zero->set_value(0L);
	r->returnValues.push_back(zero);
	func->block.push_back(r);

	auto* x = func->makeGen(parent);
	auto* p = new GoGen(x);
	// auto* g = AstImport::loadClass("si", "Coroutine");
	p->type = CLangModule::getStruct("si", "Coroutine");
	return p;
}
