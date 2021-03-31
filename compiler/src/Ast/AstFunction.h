#pragma once
#include <deque>
#include "AstLet.h"
#include "CodeGenerate/CallGen.h"

class FunctionInstance;
class ClassInstanceType;
class ClassContext;

struct FunctionArgument
{	// 参数定义
	std::string name;
	AstType* type = nullptr;
	AstNode* value = nullptr;
	CodeGen* defaultValue = nullptr;
};

/**
 *	普通函数区块
 */
class AstFunction : public AstNode {
	friend class AstCall;
	friend class AstClass;
public:
	virtual void draw(std::ostream& os);
	void genDefaultValue(AstContext* context);

	CodeGen * makeCast(llvm::LLVMContext&, std::vector<CodeGen*> cache, AstType * type, CodeGen * value);

	/// 本函数判断给定的参数是否符合本函数
	CallGen* makeCall(AstContext*, 
		const std::vector<std::pair<std::string, CodeGen*>>& types, 
		CodeGen* classObject = nullptr, 
		ClassInstanceType* clsType = nullptr,
		std::map<std::string, AstType*>* templateVars = nullptr
	);
	CallGen* makeCLangCall(AstContext*,
		const std::vector<std::pair<std::string, CodeGen*>>& types);
	virtual CodeGen* makeGen(AstContext* parent);
	std::map<std::string, AstAnnotation*> annotations;
	enum class SLFunctionType { Func = 0, Method = 1, Constructor = 2, Destructor = 3, Set = 4, Get = 5, Lambda = 6, Operator = 7, CLangFunc = 8 };
public:
	// 对于成员函数，如果类是模板的，那么函数需要复制给固化类
	AstFunction* clone();

	std::string pathName;
	std::string cLangFunction;	// c 语言函数名

	bool overload = false;
	bool isProctected = false;	// 是否被保护成员

	std::vector< FunctionArgument > paremeters;		// 参数表
	std::vector< AstLet* > rets;			// 返回值
	std::vector<AstNode*> block;			// 函数区块
	bool isOperator = false;				// 操作符（操作符重载时使用）
	AstType* variable = nullptr;			// 可变参数的类型
	std::string variableName;
	SLFunctionType funcType;

	struct OrderedParameters {
		std::vector<std::pair<std::string, CodeGen*>> parameters;
		std::vector<CodeGen*> variableGen;
	};
	/// 尝试按签名参数整理为匹配的参数，参数不匹配返回 nullptr
	OrderedParameters* orderParameters(
		AstContext*,
		const std::vector<std::pair<std::string, CodeGen*>>& types,
		const std::map<std::string, AstType*>* mapedTemplateTypes = nullptr,
		bool force = false
	);
	
	FunctionInstance * getFunctionInstance(
		llvm::LLVMContext& c,
		std::vector<std::pair<std::string, CodeGen*>> parameterGens,
		std::vector<CodeGen*> variableGen,
		ClassInstanceType* object = nullptr
	);

	bool isTemplate() const { return _isTemplate; }
	bool def = false;	// 是否仅仅是定义
private:
	void fillFunctionBlock(AstContext *context, FunctionInstance*);
	FunctionInstance* getLLVMFunctionInstance(
		llvm::LLVMContext& c,
		std::vector<std::pair<std::string, llvm::Type*>> parameters,
		ClassInstanceType* object
	);
private:
	AstContext *_parent;
	AstClass *_cls = nullptr;
	bool _isTemplate = false;
	// 保存非模板函数
	FunctionInstance *_funcInstance = nullptr;
    // 保存模板函数生成的函数，key 是类型组合
	std::unordered_map<std::string, FunctionInstance*> _functionInstances;
};
