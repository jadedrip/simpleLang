#include "stdafx.h"
#include <llvm/IR/Module.h>
#include "AstCall.h"
#include "AstContext.h"
#include "AstClass.h"
#include "modules.h"
#include "FunctionInstance.h"
#include "AstFunction.h"
#include "utility.h"
#include "AstModule.h"
#include "CodeGenerate/CallGen.h"
#include "CodeGenerate/LambdaGen.h"
#include "CodeGenerate/ParamenterGen.h"
#include "CodeGenerate/CLangCallGen.h"
#include "../Type/LLVMType.h"
#include "../Type/ClassInstanceType.h"
#include "ClassContext.h"
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
		if (name == "Init") {
			auto *x=dynamic_cast<ClassContext*>(parent);
			assert(x);
			auto *h=parent->findSymbolValue("this");
			auto* p=x->getClassType()->makeCall(parent->context(), "Init", gens, h);
			if(p) return p;
		} else {
			AstClass *cls = parent->findClass(name);
			if (cls) {	// 类初始化
				return cls->makeNew(parent, gens);
			}
		}

		throw std::runtime_error("找不到匹配的类：" + name);
	}
	
	// 查找函数
	CodeGen* g = parent->makeCall(c, name, gens);
	if (g) return  g;

	// 尝试调用纯 c 函数
	auto* p = CLangModule::getFunction(name);
	if (p) {
		std::vector<CodeGen*> params;
		for (auto i : gens) {
			params.push_back(i.second);
		}
		return new CLangCallGen(p, std::move(params));
	}

	// 查找变量
	if (!p) {
		auto v = parent->findSymbolValue(name);
		if (v) {
			std::clog << "Labmda " << name << std::endl;
			if (!v->type->isPointerTy()
				|| !v->type->getPointerElementType()->isFunctionTy())
				throw std::runtime_error("变量" + name + "不是函数");

			auto *x=dynamic_cast<ParamenterGen*>(v);
			if (x && x->type->isPointerTy()) {
				auto ft=dyn_cast<FunctionType>(x->type->getPointerElementType());
				std::vector<CodeGen*> params;
				for (auto i : gens) {
					params.push_back(i.second);
				}
				return new CallGen(x, ft, std::move(params));
			}

			// 如果是 Lambda 函数
			auto *ins=dynamic_cast<LambdaGen*>(v);
			if (ins) {
				return ins->makeCall(parent, gens);
			}else{
				throw runtime_error("还未支持");
			}
		}
	}
	if (p) {
		std::vector<CodeGen*> params;
		for (auto i : gens) {
			params.push_back(i.second);
		}
		return new CLangCallGen(p, std::move(params));
	}
	throw std::runtime_error("找不到匹配的函数：" + name);
}
