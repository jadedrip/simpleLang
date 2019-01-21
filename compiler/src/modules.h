#pragma once
#include <filesystem>
#include <llvm/IR/Module.h>

class AstPackage;
class AstContext;
class CLangModule {
public:
	static llvm::Function* getFunction(const std::string& full_name);
	static llvm::Function* CLangModule::getFunction(const std::string& package, const std::string & name);
	static void moveAll(llvm::ExecutionEngine* engine);
	static llvm::Module* loadLLFile(const std::string & file);
	static AstContext* loadSiFile(const std::experimental::filesystem::path& file, const std::string& packageName, llvm::Module* m);
	static void shutdown();
	static llvm::StructType* getStruct(const std::string& path, const std::string& name);
};
