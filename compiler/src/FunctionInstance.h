#pragma once
#include "AstContext.h"
#include "CodeGenerate/CallGen.h"

class AstFunction;
class ClassInterface;
class CodeGen;

/**
	函数类的实例
*/
class FunctionInstance
{
public:
	FunctionInstance(llvm::Function * f = nullptr);
	std::string module;
	std::string name;
	std::vector< std::pair<std::string, const llvm::Type*> > parameters;		// 参数表
	std::map<std::string, size_t> paramenterMap; // 参数索引
	std::map<size_t, CodeGen*> paramenterDefaultValues;// 默认值
	llvm::Type* returnType = nullptr;			// 返回值类型
	std::vector<CodeGen*> block;
	bool variable = false;
	llvm::StructType* object = nullptr;
public:
	llvm::Function* generateCode(llvm::Module*, llvm::LLVMContext& context);
	// static CallGen* makeCall(llvm::Function*, std::vector<std::pair<std::string, CodeGen*>>& arguments, CodeGen* object = false) { return nullptr; }
	llvm::Function* func = nullptr;
};
