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
*/
class AstClass : public AstNode {
public:
	virtual CodeGen* makeGen(AstContext* parent);
	CodeGen* makeNew(AstContext* parent, std::vector<std::pair<std::string, CodeGen*> >& args );
	// ClassInstanceType* getInstance(std::vector<std::pair<std::string, CodeGen*> >& args);
public:
	bool singleton = false;
	std::map<std::string, AstAnnotation*> annotations;
	AstGetClass* inherit = nullptr;	// 继承
	std::vector<AstNode*> block;

	std::map<std::string, AstType* > memberTypes;
	std::map<std::string, CodeGen* > constValues;
private:
	AstFunction * _construstor = nullptr;	// 构造函数
	// 类的上下文，为类定义时的上下文
	AstContext* _parent;
	bool _templated = false;
	ClassInstanceType* _generated = nullptr;
private:
	ClassInstanceType* generateClass(
		llvm::LLVMContext& c,
		AstFunction::OrderedParameters *ordered
	);
};
