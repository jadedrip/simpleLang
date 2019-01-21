#include "stdafx.h"
#include <llvm/IR/Module.h>
#include "AstCall.h"
#include "AstContext.h"
#include "AstClass.h"
#include "modules.h"
#include "FunctionInstance.h"
#include "AstFunction.h"
#include "utility.h"
#include "AstPackage.h"
#include "CodeGenerate/CallGen.h"
#include "../Type/LLVMType.h"
#include "../Type/ClassInstanceType.h"
using namespace std;

using namespace llvm;
extern std::unique_ptr<Module> module;
std::string make(const std::string& name, const vector<pair<string, AstNode*>> arguments)
{
	std::string n = "Call " + name + "(";
	if (arguments.empty()) {
		n.push_back(')');
		return n;
	}

	for (auto i : arguments) {
		//if (i.value->type)
		//	n += i.value->type->name + " " + i.value->name + ",";
		//else if (i.type)
		//	n += i.type->name + " " + i.value->name + ",";
		//else
		//	n += i.value->name + ",";
	}
	n.pop_back();
	n.push_back(')');
	return n;
}


void AstCall::draw(std::ostream & os) {

	std::string n = make(name, arguments);
	dotLable(os, n);

	if (_func) {
		// dotPointTo(os, _func, false);
	}
}

using namespace llvm;

std::vector<std::pair<std::string, CodeGen*> > AstCall::getArguments(AstContext * parent)
{
	std::vector<std::pair<std::string, CodeGen*> > gens;
	// 预处理参数
	for (auto &i : arguments) {
		if (i.second) {
			auto x = i.second->makeGen(parent);
			gens.push_back(std::make_pair(i.first, x));
		} else {
			throw std::runtime_error("函数 " + name + " 的无参数");
		}
	}
	return gens;
}

CodeGen * AstCall::makeGen(AstContext * parent)
{
	llvm::LLVMContext& c = parent->context();
	std::vector<std::pair<std::string, CodeGen*> > gens = getArguments(parent);

	// 如果首字母是大写，说明是类构造
	if (isupper(name.at(0))) {
		AstClass *cls = parent->findClass(name);
		if (cls) {	// 类初始化
			return cls->makeNew(parent, gens);
		}

		throw std::runtime_error("找不到匹配的类：" + name);
	}
	
	// 查找函数
	CodeGen* g = parent->makeCall(c, name, gens);
	if (g) return  g;

	auto* p = CLangModule::getFunction(name);

	// 尝试查找纯 C 函数
	
	if (!p) {
		auto m = module.get();
		p = m->getFunction(name);
	}
	if (!p) throw std::runtime_error("找不到匹配的函数：" + name);

	auto * ins=new FunctionInstance(p);
	ins->name = name;

	auto *call = new CallGen(ins);
	for (auto &i : gens) {
		call->params.push_back(i.second);
	}
	return call;
}
