#include "stdafx.h"
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <filesystem>
#include "modules.h"

// 这个文件定义一些 llvm 内部函数

using namespace llvm;
using namespace std::experimental;

void make_c_functions(llvm::Module *module) {
	// CLangModule::loadLLFile("lib/core.ll");
}