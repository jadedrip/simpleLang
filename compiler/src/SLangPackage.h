#pragma once
#include <string>
#include "Ast\AstModule.h"

class SLangPackage
{
public:
	std::map<std::string, AstModule*> modules;	
	llvm::Module* llvmModule;
public:
	SLangPackage(const std::string& packageName);
	AstClass* importClass(const std::string& name);
private:
	void loadDynamicLibrary(const string& dllPath);
private:
	std::string _packageName;
};

