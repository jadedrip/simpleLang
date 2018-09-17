#include "stdafx.h"
#include "SArrayType.h"
#include "Ast/AstEmpty.h"
#include "CodeGenerate/NewGen.h"
#include "../AstContext.h"

AstEmpty empty;
SArrayType::SArrayType(AstType * type, AstNode* node) : 
	memberType(type), AstType(ArrayTyID) {
	length = node;
	name = type->name + "[]";
}

llvm::Type * SArrayType::llvmType(llvm::LLVMContext & context)
{
	return memberType->llvmType(context);
}

CodeGen * SArrayType::malloc(AstContext* context)
{
	auto* p = new NewGen();
	p->type = memberType->llvmType(context->context());
	p->length = length->makeGen(context);
	return p;
}

std::string SArrayType::uniqueName()
{
	return "PA" + memberType->uniqueName();
}

size_t SArrayType::hashCode()
{
	size_t seed = 0x8D98A25B;
	return hash(seed, memberType->hashCode());
}

