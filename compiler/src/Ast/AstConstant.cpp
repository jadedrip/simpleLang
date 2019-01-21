#include "stdafx.h"
#include <cstdint>
#include <string>
#include <typeindex>
#include <memory>
#include <llvm/IR/LLVMContext.h>

#include "CodeGenerate/IntegerGen.h"
#include "AstContext.h"
#include "AstConstant.h"

using namespace llvm;

CodeGen * AstConstant::makeGen(AstContext * parent)
{
	return new IntegerGen(parent->context(), _value, _bits);
}

AstConstant::AstConstant(const std::string & text) { name = text; }

void AstConstant::set_value(bool v)
{
	_bits = 1;
	_value = v ? 1 : 0;
}

void AstConstant::set_value(int32_t v)
{
	_bits = 32;
	_value = v;
}

void AstConstant::set_value(int64_t v)
{
	_bits = 64;
	_value = v;
}

