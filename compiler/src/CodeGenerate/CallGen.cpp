#include "stdafx.h"
#include "CallGen.h"
#include "StringLiteGen.h"
#include "FunctionInstance.h"
#include "caster.h"
#include <llvm/IR/Type.h>

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
			size_t v=func->paramenterMap[i.first];
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

template< typename T >
inline void putBack(llvm::IRBuilder<>&builder, std::vector< llvm::Value* >& a, llvm::Value* v, T& iter, T& end)
{
	if (iter == end)
		a.push_back(v);
	else {
		a.push_back(try_cast(builder, *iter, v));
		iter++;
	}
}

Value * CallGen::generateCode(Module *m, Function *func, llvm::IRBuilder<>&builder)
{
	if (!llvmFunction) {
		if (pointerGen) { // 函数指针
			Value* v = pointerGen->generate(m, func, builder);
			// 函数是作为指针保存的
			Type* t = PointerType::get(pointerGen->type,0);
			llvmFunction = builder.CreateBitOrPointerCast(v, t);
			llvmFunction = builder.CreateLoad(llvmFunction);
		} else {
			assert(function);
			llvmFunction = function->generateCode(m, builder.getContext());
			funcType = function->func->getFunctionType();
		}
	}

	if(function)
		function->generateBody(m, builder.getContext());

	auto iter = funcType->param_begin();
	auto end = funcType->param_end();
	std::vector< llvm::Value* > a;
	if (object)
		putBack(builder, a, object->generate(m, func, builder), iter, end);
	for (auto *i : params) {
		Value* v = i->generate(m, func, builder);
		// 如果是基本类型
		if (i->type->isIntegerTy() || i->type->isFloatingPointTy()) {
			if (v->getType()->isPointerTy())
				v = builder.CreateLoad(v);
			putBack(builder, a, v, iter, end);
		} else if (i->type->isArrayTy()) {
			putBack(builder, a, v, iter, end);
			// 写入大小
			auto sz = i->type->getArrayNumElements();
			auto* s = ConstantInt::get(func->getContext(), APInt(32, sz));
			putBack(builder, a, s, iter, end);
		} else {
			putBack(builder, a, v, iter, end);
		}
	}

	std::clog << "Call func " << llvmFunction->getName().str() << std::endl;
	
	Value* v= builder.CreateCall(funcType, llvmFunction, a);

	// 添加一个强制转换，避免某些 c 函数返回的类型不一致
	if (type->isStructTy()) {
		Type* ty = llvm::PointerType::get(type, 0);
		return builder.CreateBitOrPointerCast(v, ty);
	}
	return v;
}

llvm::CallInst * CallGen::callFunc(llvm::IRBuilder<>& builder, llvm::Function * func, std::vector<llvm::Value*>& params)
{
	llvm::raw_os_ostream os(std::cout);
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
