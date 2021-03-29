#pragma once
#include <filesystem>
#include <llvm/IR/Module.h>
#include "Ast/AstPackage.h"

class AstModule;
class AstContext;
class AstClass;
class AstFunction;
struct IDirectory;
class CLangModule {
public:
	static llvm::Function* getFunction(const std::string& full_name);
	static llvm::Function* getFunction(const std::string& package, const std::string & name);
	static void moveAll(llvm::ExecutionEngine* engine);
	// static llvm::Module* loadLLFile(const std::string & file);
	static AstModule* loadSiFile(const std::filesystem::path& file, const std::string& packageName);
	static void shutdown();
	//static llvm::StructType* getStruct(const std::string& path, const std::string& name);
	//static llvm::StructType* getStruct(const std::string& name);
	static AstPackage* loadPackage(const std::string& name);
};
