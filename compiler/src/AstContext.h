#pragma once
#include <set>
#include <utility>
#include <unordered_map>
#include <llvm/IR/Module.h>
#include "Ast/AstNode.h"
#include "Ast/AstClass.h"

#define Interface struct

class AstType;
class ClassInstanceType;
class FunctionInstance;
class AstPackage;
class AstFunction;
class CodeGen;
class EnumType;

/**
	这里定义了一个上下文
	*/
class AstContext
{
public:
	AstContext(AstContext* p);
	AstContext(llvm::Module * m);
	AstContext* parent;
	llvm::Module* module = nullptr;
	llvm::LLVMContext& context();

	std::string pathName;
public:
	// 通过变量名称获取变量的值
	virtual CodeGen* findSymbolValue(const std::string& name, bool recursive = true);
	// 通过变量的名称设置变量的值
	virtual void setSymbolValue(const std::string& name, CodeGen* v);

	virtual void defineFunction(const std::string& name, AstFunction*);

	void setClass(const std::string& name, AstClass* cls);
	AstClass* findClass(const std::string& name);
	ClassInstanceType* findCompiledClass(const std::string& name);
	static ClassInstanceType* findCompiledClassByLLVMType(const llvm::Type* type);

	void setCompiledClass(const std::string& name, ClassInstanceType* cls)
	{
		_compiledClass[name] = cls;
	}

	static AstClass* loadClass(const std::string& path, const std::string& name);

	/// <summary>
	/// 通过名称和参数查找函数，如果找到参数将被整理
	/// </summary>
	/// <param name="name">函数名</param>
	/// <param name="arguments">参数表</param>
	/// <returns>调用函数</returns>
	virtual CodeGen* makeCall(
		llvm::LLVMContext& c,
		const std::string& name,
		std::vector<std::pair<std::string, CodeGen*>>& arguments,
		CodeGen* object = nullptr
	);
	virtual AstType* findType(const std::string& name);
public:
	std::multimap<std::string, AstFunction*> _functions;		 // 模板函数
	std::unordered_map< std::string, AstClass* > _class;			// 未特例化的自定义结构
	std::unordered_map< std::string, CodeGen* > _symbols;	// 变量
	std::map<std::string, EnumType*> _enums;    //	保存枚举变量			
private:
	/* 
	* 记录 c 的 struct 到 ClassInstanceType 的映射，以便
	*  “点”生成器对 cls.method() 这样的代码，能够快速通过类名反查类
	*/
	static std::map<std::string, ClassInstanceType* > _compiledClass;
};
