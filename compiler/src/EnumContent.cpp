#include "stdafx.h"
#include "CodeGenerate/IntegerGen.h"
#include "EnumContent.h"

EnumContext::EnumContext(AstContext * context, std::map<std::string, CodeGen*>&& enums)
	: AstContext(context), _codes(enums)
{
}

CodeGen * EnumContext::findSymbolValue(const std::string & name, bool recursive)
{
	auto iter = _codes.find(name);
	if (iter == _codes.end())
		return parent->findSymbolValue(name, recursive);
	return iter->second;
}

void EnumContext::setSymbolValue(const std::string & name, CodeGen * v)
{
	parent->setSymbolValue(name, v);
}
