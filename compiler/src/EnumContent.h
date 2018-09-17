#pragma once
#include "AstContext.h"

class EnumType;
class EnumContext : public AstContext {
public:
	EnumContext(AstContext* context, std::map<std::string, CodeGen* >&& enums);
	virtual CodeGen* findSymbolValue(const std::string& name, bool recursive = true);
	virtual void setSymbolValue(const std::string& name, CodeGen* v);
private:
	std::map<std::string, CodeGen*> _codes;
};