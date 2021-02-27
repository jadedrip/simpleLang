#pragma once
#include <set>
#include "AstContext.h"
#include "CodeGenerate/CallGen.h"
#include "CodeGenerate/BlockGen.h"

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
	std::string packageName;
	std::string name;
	std::vector< std::pair<std::string, const llvm::Type*> > parameters;		// 参数表
	llvm::Type* returnType = nullptr;			// 返回值类型
	BlockGen block;
	llvm::StructType* object = nullptr;
	bool overload = false;
	std::set<std::string> excapes; // 逃逸的参数索引
	void generateBody(llvm::Module *m, llvm::LLVMContext & context);
public:
	llvm::Function* generateCode(llvm::Module*, llvm::LLVMContext& context);
	llvm::Function* func = nullptr;
	void setVariable(bool v = true);
	size_t getParamenterIndex(const std::string& name);

	std::string cName;	// c 语言函数名
private:
	bool _body = false;
	bool _variable = false;
	std::map<std::string, size_t> _paramenterMap; // 参数索引
};
