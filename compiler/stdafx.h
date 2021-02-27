// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include <cstdint>

#include <set>
#include <array>
#include <regex>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include <exception>
#include <functional>
#include <unordered_map>
#include <cassert>
#include <filesystem>

#pragma warning( push, 1 )
#pragma warning( disable : 4996 4624 4291 4141 4244 )
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_os_ostream.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/ADT/APInt.h>
#include <llvm/Support/Chrono.h>
#include <llvm/Support/MathExtras.h>
#include <llvm/Support/Allocator.h>
#include <clang/AST/StmtOpenMP.h>
#include <clang/AST/DeclCXX.h>
#pragma warning( pop )

#include "../src/logger/logger.h"