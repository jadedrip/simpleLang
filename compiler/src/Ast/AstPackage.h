#pragma once
#include <filesystem>
#include <llvm/IR/DerivedTypes.h>

class AstClass;
class AstModule;
class AstPackage
{
public:
	AstPackage(const std::string& name);
	void addModule(const std::string& name, AstModule* module);
	std::string& name() const { _name; }
	AstClass* findClass(const std::string& name);
	llvm::StructType* findStruct(const std::string& name) {
		auto iter = _structs.find(name);
		return (iter == _structs.end()) ? nullptr : iter->second;
	}

	llvm::Function* getFunction(const std::string& name) {
		return _llvmModule ? _llvmModule->getFunction(name) : nullptr;
	}
private:
	void recurvePath(const std::string& base, const std::filesystem::path& path);
	void importDll(const std::filesystem::path& base);
private:
	std::string _name;
	llvm::Module* _llvmModule = nullptr;

	std::map<std::string, AstModule*> _modules;
	std::map<std::string, llvm::StructType*> _structs;
	std::map<std::string, llvm::Function*> _functions;
};

