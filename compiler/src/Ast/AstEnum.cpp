#include "stdafx.h"
#include "AstEnum.h"
#include "AstLet.h"
#include "AstContext.h"
#include "CodeGenerate/TypeOnlyGen.h"
#include "CodeGenerate/IntegerGen.h"
#include "CodeGenerate/IntegerBinaryGen.h"
#include "../Type/ClassInstanceType.h"
#include "../Type/SIntegerType.h"

void AstEnum::draw(std::ostream & os) {
	dotLable(os, name);
}

CodeGen * AstEnum::makeGen(AstContext * parent)
{	 
    // enum 处理为类内的常量
	parent->setClass(name, this);
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

			constValues[i->name] = idx;
			if (++iter == values.end()) break;
		}
	}
	
	return nullptr;
}

