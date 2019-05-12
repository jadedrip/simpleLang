#include "stdafx.h"
#include "Type/AstType.h"
#include "AstNewArray.h"
#include "AstContext.h"
#include "AstGetClass.h"
#include "CodeGenerate/NewGen.h"

CodeGen* AstNewArray::makeGen(AstContext* context)
{
	auto* x = dynamic_cast<AstGetClass*>(type);
	if (x) {
		x->context = context;
	}
	auto *p=new NewGen();
	p->length=expr->makeGen(context);
	p->type = type->llvmType(context->context());
	return p;
}
