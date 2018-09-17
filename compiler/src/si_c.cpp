#include "stdafx.h"
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <filesystem>
#include "modules.h"

// 这个文件定义一些 llvm 内部函数

using namespace llvm;

void make_printf(llvm::Module *module) {
	using namespace llvm;
	std::vector<Type *> params;
	params.push_back(Type::getInt8PtrTy(module->getContext(), 0));

	FunctionType *fType = FunctionType::get(
		Type::getInt32Ty(module->getContext()), params, true);

	 Constant *temp = module->getOrInsertFunction("printf", fType);
	if (!temp) {
		std::cerr << "printf function not in symbol table\n";
		exit(1);
	}

	// CLangModule::add("c", module);
}

using namespace std::experimental;

void make_c_functions(llvm::Module *module) {
	make_printf(module);
	CLangModule::loadLLFile("lib/core");
}