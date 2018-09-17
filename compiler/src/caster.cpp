#include "stdafx.h"
#include "caster.h"
#include "utility.h"
#include "modules.h"
#include "CodeGenerate/CallGen.h"

using namespace std;
using namespace llvm;
Value* structCast(IRBuilder<>& builder, Type* dest, Value *v)
{
	Type* r = v->getType()->getPointerElementType();

	string n = toReadable(r);
	if (dest->isPointerTy()) {
		auto *x = dest->getPointerElementType();
		if (x->isStructTy())
			dest = x;
	}
	string to = toReadable(dest);
	string name = n + "_Cast_" + to;
	auto* func = CLangModule::getFunction(name);// find the cast function
	if (func) {
		return CallGen::call(builder, func, v);
	}
	return v;
}

/**
 *	这个函数尝试对基本变量进行隐式转换
 */
Value* try_cast(IRBuilder<>& builder, Type* dest, Value *v)
{
	if (!dest || !v) return v;
	Type* r = v->getType();
	if (r == dest)
		return v;

	if (dest->isIntegerTy() && r->isIntegerTy()) {
		return builder.CreateSExtOrTrunc(v, dest);
	} else if (dest->isFloatingPointTy() && r->isFloatingPointTy()) {
		if (dest->getIntegerBitWidth() > r->getIntegerBitWidth()) {
			return builder.CreateFPExt(v, dest);
		} else if (dest->getIntegerBitWidth() < r->getIntegerBitWidth()) {
			return builder.CreateFPTrunc(v, dest);
		} else {
			return v;
		}
	} else if (dest->isIntegerTy() && r->isFloatingPointTy()) {
		return builder.CreateFPToSI(v, dest);
	} else if (dest->isFloatingPointTy() && r->isIntegerTy()) {
		return builder.CreateSIToFP(v, dest);
	} 

	if (r->isPointerTy()) {
		r = r->getPointerElementType();
		if (r == dest)
			return builder.CreateLoad(v);
		if (r->isStructTy()) {
			return structCast(builder, dest, v);
		}
	}
	return v;
}
