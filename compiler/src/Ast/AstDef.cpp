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
using namespace std;
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
		auto x=vars.at(0);
		auto gen= makeDefGen(parent, p, x.first, x.second);
		if (!gen)
			throw std::runtime_error("Can't def " + x.first);
		parent->setSymbolValue(x.first, gen );
		return gen;
	}
	
	auto list = new GenList();
	for (auto &i : vars) {
		auto gen = makeDefGen(parent, p, i.first, i.second);
		list->generates.push_back(gen);
		parent->setSymbolValue(i.first, gen);
	}

	return list;
}

static string emptyStr;
CodeGen * AstDef::makeDefGen(AstContext * parent, AstType * type, const std::string& n, AstNode* var)
{
	CodeGen*  v = var ? var->makeGen(parent) : nullptr;
	if (v && !type && v->type->isStructTy())
		return v;

	llvm::Type* t = nullptr;

	LLVMContext& c = parent->context();

	auto *a = dynamic_cast<AstGetClass*>(type);
	if (a) {
		a->context = parent;
		// 创建新对象
		auto *x = parent->findClass(a->name);
		if (x) {
			// TODO: 测试 x 类型和 v 一致
			if (v) return v;

			vector<pair<string, CodeGen*>> args;
			return x->makeNew(parent, args);
		}
	} else if (type) {
		t = type->llvmType(parent->context());
	} else if (v)
		t = v->type;
	
	return new DefGen(n, t, v);
}
