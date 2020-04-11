#pragma once
#include <string>
#include "Ast\AstModule.h"

class SLangPackage
{
public:
	std::string packageName;
	std::map<std::string, AstModule*> modules;	
	llvm::Module* llvmModule;
public:
	void load(const std::string& name);
private:
	void loadDynamicLibrary(const string& dllPath);
};

