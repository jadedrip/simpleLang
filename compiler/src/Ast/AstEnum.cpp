#include "stdafx.h"
#include "AstEnum.h"
#include "AstLet.h"
#include "AstContext.h"
#include "CodeGenerate/TypeOnlyGen.h"
#include "CodeGenerate/IntegerGen.h"
#include "CodeGenerate/IntegerBinaryGen.h"
#include "../Type/EnumType.h"
#include "../Type/SIntegerType.h"

void AstEnum::draw(std::ostream & os) {
	dotLable(os, name);
}

// enum 
CodeGen * AstEnum::makeGen(AstContext * parent)
{	 
	auto *type = new EnumType();
	CodeGen* idx = nullptr;
	IntegerBinaryGen* p;
	if (!values.empty()) {
		auto iter = values.begin();
		while(true){
			auto i = *iter;
			if (i->right) 
				idx = i->right->makeGen(parent);
			else if(!idx)
				idx = new IntegerGen(parent->context(), 0);
			else {
				p = new IntegerBinaryGen('+', idx, new IntegerGen(parent->context(), 1));
				idx = p;
			}

			type->enums[i->name] = idx;
			if (++iter == values.end()) break;
		}
	}
	
	auto llvmType = type->llvmType(parent->context());
	auto *x=new TypeOnlyGen(llvmType);
	parent->setSymbolValue(name, x);
	return x;
}

