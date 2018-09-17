#pragma once
#include <deque>
#include "AstLet.h"

class FunctionInstance;
class ClassInstanceType;

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
public:
	virtual void draw(std::ostream& os);

	CodeGen * makeCast(llvm::LLVMContext&, std::vector<CodeGen*> cache, AstType * type, CodeGen * value);

	/// 本函数判断给定的参数是否符合本函数
	CodeGen* makeCall(llvm::LLVMContext& c, std::vector<std::pair<std::string, CodeGen*>>& types, CodeGen* classObject = nullptr);

	virtual CodeGen* makeGen(AstContext* parent);
	enum FunctionType { Func=0, Method=1, Constructor=2, Destructor=3, Set=4, Get=5, Lambda=6, Operator=7 };
public:
	std::string pathName;

	bool overload = false;

	std::vector< FunctionArgument > paremeters;		// 参数表
	std::vector< AstLet* > rets;			// 返回值
	std::vector<AstNode*> block;					// 函数区块
	int op = 0;										// 操作符（操作符重载时使用）
	AstType* variable = nullptr;					// 可变参数的类型
	std::string variableName;
	FunctionType funcType;						// 
	FunctionInstance* noTemplateInstance = nullptr;

	struct OrderedParameters {
		std::vector<std::pair<std::string, CodeGen*>> parameters;
		std::vector<CodeGen*> variableGen;
	};
	/// 尝试按签名参数整理为匹配的参数，参数不匹配返回 nullptr
	OrderedParameters* orderParameters(llvm::LLVMContext& c, std::vector<std::pair<std::string, CodeGen*>>& types);
	AstType* getTypeByName(const std::string& name);
	CodeGen * createCallGen(llvm::LLVMContext& c, std::vector<std::pair<std::string, CodeGen*>>& parameters, std::vector<CodeGen*>& variableGen, CodeGen* object = nullptr, FunctionInstance* instance=nullptr);
	FunctionInstance * getFunctionInstance(llvm::LLVMContext& c, std::vector<std::pair<std::string, CodeGen*>> parameterGens, std::vector<CodeGen*> variableGen, ClassInstanceType* object = nullptr);
	FunctionInstance * getFunctionInstance(
		llvm::LLVMContext& c,
		std::vector<std::pair<std::string, llvm::Type*>> parameters,
		AstType* variableGen,
		ClassInstanceType* object
	);
	void fillFunctionBlock(AstContext *context, FunctionInstance*);
private:
	std::map<std::string, FunctionArgument> named;
	AstContext *_parent;

	
};
