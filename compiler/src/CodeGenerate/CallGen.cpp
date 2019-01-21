#include "stdafx.h"
#include "CallGen.h"
#include "StringLiteGen.h"
#include "FunctionInstance.h"
#include "caster.h"

using namespace llvm;
CallGen::CallGen(FunctionInstance * func) : function(func)
{
}

CallGen::CallGen(FunctionInstance * func, std::vector<CodeGen*>&& attrs) : function(func), params(attrs) 
{ 
	assert(func); 
}

CallGen::CallGen(FunctionInstance* func, const std::vector<std::pair<std::string, CodeGen*>>& paramters, CodeGen* object)
	: function(func)
{
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
			size_t v=func->paramenterMap[i.first];
			if (idx != v) idx = std::string::npos;
			params[v] = i.second;
		}

		// TODO: 可变参数支持
	}


	// TODO: 默认值支持
	//for (auto i = 0; i < s; i++) {
	//	if (!x[i]) {
	//		func->object
	//	}
	//}
}

inline bool checkIsClass(Type* type)
{
	if (!type->isPointerTy()) return false;
	auto* p=type->getPointerElementType();
	return p->isStructTy();
}

Value * CallGen::generateCode(Module *m, Function *func, llvm::IRBuilder<>&builder)
{
	if (!llvmFunction) {
		assert(function);
		llvmFunction = function->generateCode(m, builder.getContext());
	}
	std::clog << "Call " << llvmFunction->getName().str() << ' ';

	std::vector< llvm::Value* > a;
	auto *argIterator= llvmFunction->arg_begin();
	for (auto *i : params) {
		if (argIterator != llvmFunction->arg_end())
			i->hopeType = argIterator->getType();
		Value* v = i->generate(m, llvmFunction, builder);

		if (!v) {
			assert(i->hopeType);
			v = ConstantInt::getNullValue(i->hopeType);
		} 

		if (i->hopeType && v->getType() != i->hopeType && v->getType()->isPointerTy() ) {
			if(!i->hopeType->isPointerTy())
				v = load(builder, v);
			else {
				assert(0 && "Not match.");
			}
		}

		if (argIterator == llvmFunction->arg_end()) {	// 可变参数
			std::clog << toReadable(v->getType()) << ", ";
			a.push_back(v);
		}
		else {
			std::clog << toReadable(v->getType()) << ", ";
			a.push_back(try_cast(builder, i->hopeType, v));
			argIterator++;
			// 对于数组，改为数据+长度2个参数
			if (i->type && i->type->isArrayTy()) {
				auto sz = i->type->getArrayNumElements();
				assert(argIterator != llvmFunction->arg_end());
				auto hope = argIterator->getType();
				auto* v=ConstantInt::get(hopeType, sz);
				a.push_back(v);
				argIterator++;
			}
		}
	}
	std::clog << std::endl;

	std::clog << "Call " << llvmFunction->getName().str() << std::endl;
	return builder.CreateCall(llvmFunction, a);
}

llvm::CallInst * CallGen::callFunc(llvm::IRBuilder<>& builder, llvm::Function * func, std::vector<llvm::Value*>& params)
{
	std::vector< llvm::Value* > a;
	auto *argIterator = func->arg_begin();
	std::clog << "Call " << func->getName().str() << ' ';
	for (auto *i : params) {
		if (argIterator != func->arg_end()) {
			auto *tp = argIterator->getType();
			auto *to = try_cast(builder, tp, i);
			a.push_back(to);
			argIterator++;
			std::clog << toReadable(i->getType()) << ", ";
		} else if (func->isVarArg()) {
			a.push_back(i);
			std::clog << toReadable(i->getType()) << ", ";
		} else
			throw std::runtime_error("To many paramter for " + func->getName().str());
	}
	std::clog << std::endl;

	return builder.CreateCall(func, a);
}
