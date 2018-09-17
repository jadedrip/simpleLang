#include "stdafx.h"
#include "AstDef.h"
#include "AstContext.h"
#include "AstGetClass.h"
#include "utility.h"
#include "../Type/AutoType.h"
#include "../Type/ClassInstanceType.h"
#include "../CodeGenerate/DefGen.h"
#include "../CodeGenerate/GenList.h"
#include "../CodeGenerate/CastGen.h"
#include "../CodeGenerate/StringLiteGen.h"
#include <exception>

using namespace llvm;
void AstDef::draw(std::ostream & os)
{
	std::string n = "def ";
	for (auto &i : vars) {
		n += i.first + ",";
	}
	n.pop_back();
	dotLable(os, n);
}

CodeGen * AstDef::makeGen(AstContext * parent)
{
	AstType* p = AutoType::isAuto(type) ? nullptr : type;

	if (vars.size() == 1) {
		auto gen= makeDefGen(parent, p, vars.at(0));
		parent->setSymbolValue(gen->name, gen );
		return gen;
	}
	
	auto list = new GenList();
	for (auto &i : vars) {
		auto gen = makeDefGen(parent, p, i);
		list->generates.push_back(gen);
		parent->setSymbolValue(i.first, gen);
	}

	return list;
}

DefGen * AstDef::makeDefGen(AstContext * parent, AstType * type, const std::pair<std::string, AstNode*> & i)
{
	std::string n = i.first;
	CodeGen*  v = nullptr;
	llvm::Type* t = nullptr;

	LLVMContext& c = parent->context();

	auto *a = dynamic_cast<AstGetClass*>(type);
	if (a) {
		auto x = parent->findCompiledClass(a->name);
		if (x) {
			t = x->llvmType(parent->context());
		} 
	} else if(type) {
		t = type->llvmType(parent->context());
	}
	
	if (i.second) { // 如果有值
		v = i.second->makeGen(parent);	  	// p==null 说明是 = null 禁止创建

		if (!t) {
			if (!type || isType<AutoType>(type)) {
				if (isType<StringLiteGen>(v)) {// 对字符串特殊处理
					auto sty = parent->findCompiledClass("String");
					t = sty->llvmType(parent->context());
				} else if (v)
					t = v->type;
			}
		}

		if (v) {
			if (isType<StringLiteGen>(v) && v->type != t) {
				v = new CastGen(t, v);
			}
		}
	} 

	return new DefGen(n, t, v);
}
