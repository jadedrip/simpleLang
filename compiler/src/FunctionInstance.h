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
	llvm::Type* returnType = nullptr;			// 返回值类型
	std::vector<CodeGen*> block;
	bool variable = false;
	llvm::StructType* object = nullptr;
	bool overload = false;

	void generateBody(llvm::Module *m, llvm::LLVMContext & context);
public:
	llvm::Function* generateCode(llvm::Module*, llvm::LLVMContext& context);
	llvm::Function* func = nullptr;
private:
	bool _body = false;
};
