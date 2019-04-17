#include "stdafx.h"
#include "AstDot.h"
#include "AstLet.h"
#include "AstCall.h"
#include "ClassContext.h"
#include "CodeGenerate/CodeGen.h"
#include "Type/ClassInstanceType.h"

using namespace llvm;

AstDot::AstDot(AstNode * o, AstNode * r)
	: object(o), right(r)
{
}

CodeGen * AstDot::makeGen(AstContext * parent)
{
	assert(right);
	auto o = object->makeGen(parent);
	if (!o->type)
		throw std::runtime_error("Can't use " + object->name + " before new");
	auto x = o->type->isStructTy();
	if (x) {	// 如果左边是对象
		auto sty = dyn_cast<StructType>(o->type);
		// 右值有两种可能，call or getmember
		auto *c=dynamic_cast<AstCall*>(right);
		if (c) {
			auto * cls=parent->findCompiledClass(sty->getName());
			if (!cls)
				throw std::runtime_error("Can't find class:" + sty->getName().str());
			auto p = cls->makeCall(parent->context(), right->name, c->getArguments(parent), o);
			p->parameter = o->parameter;
			return p;
		}

		auto* cls = parent->findCompiledClass(sty->getName());
		if (!cls)
			throw std::runtime_error("Can't find member:" + sty->getName().str());
		auto p=cls->getMember(o, right->name);
		p->parameter = o->parameter;
		return p;
	}
	else {
		throw std::runtime_error("点的左边不是对象类型");
	}
}

void AstDot::draw(std::ostream & os) {
	std::string n = nodeId;
	os << n << " -> " << object->nodeId << std::endl;
	os << n << " -> " << right << std::endl;
	os << n << "[label=\".\"]" << std::endl;
	object->draw(os);
}


