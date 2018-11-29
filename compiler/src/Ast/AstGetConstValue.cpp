#include "stdafx.h"
#include "AstGetConstValue.h"
#include "AstContext.h"

AstGetConstValue::AstGetConstValue(const char * className, const char * member) :
	_className(className), _member(member)
{

}

void AstGetConstValue::draw(std::ostream & os)
{
	dotLable(os, "get enum "+_className + "." + _member);
}

CodeGen * AstGetConstValue::makeGen(AstContext * parent)
{
	auto *p=parent->findClass(_className);
	if (p) {
		auto iter=p->constValues.find(_member);
		if (iter != p->constValues.end())
			return iter->second;
	}
	throw std::runtime_error("Can't find: " + _className + "." + _member);
}
