#pragma once
#include <tuple>
#include "AstFunction.h"
#include "AstAnnotation.h"
#include "../Type/AstType.h"

class AstDef;
class AstGetClass;
class ClassInstanceType;

/**
*	原始类区块
*	仅仅在类构造使用，当类被构造，也就确认了类型，生成 ClassInstanceType
*/
class AstClass : public AstNode {
public:
	virtual CodeGen* makeGen(AstContext* parent);
	CodeGen* makeNew(
		AstContext* parent, 
		std::vector<std::pair<std::string, CodeGen*> >& args, 
		std::vector<AstType*>* templateTypes = nullptr
	);
	// ClassInstanceType* getInstance(std::vector<std::pair<std::string, CodeGen*> >& args);
public:
	bool singleton = false;
	std::map<std::string, AstAnnotation*> annotations;
	AstGetClass* inherit = nullptr;	// 继承
	std::vector<AstNode*> block;
	std::string cStructName; // c 函数里的名称 

	std::map<std::string, CodeGen* > constValues;
	bool isTemplated() const { return _templated; }
	// 存放模板占位符（大写）和自动变量名（小写）
	std::vector<std::string> templateVariables;

	ClassInstanceType* generated = nullptr;

	// 通过模板类型确定编译类
	ClassInstanceType* generateClass(
		AstContext*,
		std::vector<AstType*>& templateTypes
	);
private:
	std::vector<AstFunction *> _construstor;	// 构造函数
	std::vector<AstFunction*> _memberFunctions;

	struct Member {
		std::string name;
		AstType* type;
		AstNode* defaultValue;
	};
	std::vector<Member> _members;
											
	// 类的上下文，为类定义时的上下文
	AstContext* _context;
	bool _templated = false;
private:
	// 创建模板变量表
	std::map<std::string, AstType*> createMappedTemplateTypes(std::vector<AstType*>* templateTypes);
	// 向生成的类里填充成员函数
	void fillMemberFunctionsTo(AstContext*, ClassInstanceType* cls);
	// 向类中填充成员
	std::vector<llvm::Type*> fillMember(AstContext*, CodeGen*, ClassInstanceType* cls);
	ClassInstanceType* generateClass(
		llvm::LLVMContext& c,
		std::map<std::string, AstType*>& templateTypes
	);
	int scanClass(ClassInstanceType * cls, AstContext * context, CodeGen* thisGen, std::vector< llvm::Type* >& types);
};
