#pragma once
#include "AstContext.h"
#include "Type/ClassInstanceType.h"

class CodeGen;
class ClassInterface;

// 类上下文
class ClassContext : public AstContext
{
public:
	// 类定义工作模式
	ClassContext(AstContext *parent, ClassInstanceType* type);
	// 对象成员操作模式
	ClassContext(AstContext *parent, CodeGen* gen);
	// 通过变量名称查找
	virtual CodeGen* findSymbolValue(const std::string& name, bool recursive);
	CodeGen* value = nullptr;
	virtual CodeGen* makeCall(llvm::LLVMContext& c, const std::string& name, std::vector<std::pair<std::string, CodeGen*>>& arguments);
	virtual AstType* findType(const std::string& name)
	{
		auto i = templateTypes.find(name);
		if (i != templateTypes.end())
			return i->second;
		return parent ? parent->findType(name) : nullptr;
	}

	ClassInstanceType* getClassType() const { return _type; }
	std::map<std::string, AstType*> templateTypes;
private:
	ClassInstanceType* _type = nullptr;
	CodeGen * _codeGen = nullptr;
};
