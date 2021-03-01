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
#include "../GoContext.h"

AstGo::AstGo(AstNode* node) : _node(node)
{
	assert(node);
}

CodeGen * AstGo::makeGen(AstContext * context)
{
	GoContext *goContext = new GoContext(context);
	auto&c = context->context();
	auto* func = dynamic_cast<AstFunction*>(_node);
	// 如果不是函数，说明是函数调用，包装为匿名函数
	if (!func) {
		func = new AstFunction();
		func->funcType = AstFunction::SLFunctionType::Lambda;
		func->block.push_back(_node);
	} 
	// go 的匿名返回 void*, 我们改造一下
	AstLet* let = new AstLet();
	let->type = LLVMType::getVoidPtr(c);
	func->rets.push_back(let);
	auto * r = new AstReturn();
	auto *zero = new AstConstant("0");
	zero->set_value(0L);
	r->returnValues.push_back(zero);
	func->block.push_back(r);

	auto* x = func->makeGen(goContext);
	auto* p = new GoGen(x);
	p->globles = std::move(goContext->globels);
	// auto* g = AstImport::loadClass("sl", "Coroutine");
	p->type =context->findStruct("si_Coroutine");
	return p;
}
