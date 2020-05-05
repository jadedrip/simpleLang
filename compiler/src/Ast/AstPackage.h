#pragma once

class AstModule;
class AstPackage
{
public:
	AstPackage(const std::string& name);
	void addModule(const std::string& name, AstModule* module);
	std::string& name() const { _name; }
	AstClass* findClass(const std::string& name);
private:
	void recurvePath(const std::string& base, const std::filesystem::path& path);
	void importDll(const std::filesystem::path& base);
private:
	std::string _name;
	llvm::Module* _llvmModule = nullptr;

	std::map<std::string, AstModule*> _modules;
	std::map<std::string, llvm::StructType*> _structs;
};

