#include "stdafx.h"
#include <llvm/IR/Type.h>

#include "CallGen.h"
#include "StringLiteGen.h"
#include "FunctionInstance.h"
#include "caster.h"
#include "CLangCallGen.h"

using namespace llvm;
CallGen::CallGen(FunctionInstance * func) : function(func)
{
	if (func) {
		setRealType(func->returnType);
	}
}

CallGen::CallGen(FunctionInstance * func, std::vector<CodeGen*>&& attrs) : function(func), params(attrs) 
{ 
	assert(func); 
	if (func) {
		setRealType(func->returnType);
	}
}

CallGen::CallGen(FunctionInstance* func, const std::vector<std::pair<std::string, CodeGen*>>& paramters, CodeGen* object)
	: function(func)
{
	if (func) {
		setRealType(func->returnType);
	}

	const size_t s=func->parameters.size();
	size_t idx = 0;
	if (object) {
		params.push_back(object);
		idx++;
		params.resize(s+1);
	} else {
		params.resize(s);
	}

	for (auto &i : paramters) {
		if (i.first.empty()) {
			if (idx == std::string::npos) throw std::runtime_error("Can't match paramters for " + func->name);
			params[idx] = i.second;
		} else {
			size_t v=func->getParamenterIndex(i.first);
			if (idx != v) idx = std::string::npos;
			params[v] = i.second;
		}
	}
}

CallGen::CallGen(CodeGen * gen, FunctionType*ft, std::vector<CodeGen*>&& attrs)
	: pointerGen(gen), params(attrs), funcType(ft)
{
	if (ft) {
		setRealType(ft->getReturnType());
		type = ft->getReturnType();
	}
}

inline bool checkIsClass(Type* type)
{
	if (!type->isPointerTy()) return false;
	auto* p=type->getPointerElementType();
	return p->isStructTy();
}

Value * CallGen::generateCode(const Generater& generater)
{
	auto* m = generater.module;
	auto func = generater.func;
	auto& builder = generater.builder();

	if (!llvmFunction) {
		if (pointerGen) { // 函数指针
			Value* v = pointerGen->generate(generater);
			auto *x=dyn_cast<PointerType>(v->getType());

			if (x->getElementType()->isPointerTy()) {
				// 函数是作为指针保存的
				Type* t = PointerType::get(pointerGen->type, 0);
				// v = builder.CreateBitOrPointerCast(v, t);
				llvmFunction = builder.CreateLoad(v);
			} else {
				llvmFunction = v;
			}
		} else {
			assert(function);
			llvmFunction = function->generateCode(m, builder.getContext());
			assert(llvmFunction);
			funcType = function->func->getFunctionType();
		}
	}

	auto* x=dyn_cast<llvm::Function>(llvmFunction);
	assert(x);
	return CLangCallGen::call(generater, x, params, type);
}

llvm::CallInst * CallGen::callFunc(llvm::IRBuilder<>& builder, llvm::Function * func, std::vector<llvm::Value*>& params)
{
	assert(func);
//llvm::raw_os_ostream os(std::cout);
	std::vector< llvm::Value* > a;
	auto *argIterator = func->arg_begin();
	//std::clog << "Call " << func->getName().str() << ": ";
	for (auto *i : params) {
		if (argIterator != func->arg_end()) {
			auto *tp = argIterator->getType();
			auto *to = try_cast(builder, tp, i);
			a.push_back(to);
			argIterator++;
			//std::clog << getReadable(to->getType()) << ", ";
		} else if (func->isVarArg()) {
			a.push_back(i);
			//std::clog << getReadable(i->getType()) << ", ";
		} else
			throw std::runtime_error("To many paramter for " + func->getName().str());
	}
	auto call=builder.CreateCall(func, a);
	//call->print(os);
	//os.flush();

	//std::clog << std::endl;

	return call;
}
