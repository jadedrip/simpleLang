#pragma once
#include "AstType.h"
#include "AstContext.h"
#include "ClassContext.h"
#include "../CodeGenerate/CallGen.h"
#include "../CodeGenerate/ClassMemberGen.h"

class FunctionInstance;
													
class ClassInstanceType : public AstContext, public AstType
{
	friend class AstClass;
public:
	static ClassInstanceType* findByName(const std::string& name);
public:
	ClassInstanceType(AstContext* parent, const std::string& path, const std::string& name);
public:
	ClassInstanceType* inherit = nullptr; // 继承
	virtual std::string uniqueName();
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);
	/// 查询成员对象
	virtual ClassMemberGen* getMember(CodeGen* object, const std::string& name);
	CodeGen* newObject(AstContext* parent, std::vector<std::pair<std::string, CodeGen*> >& );

	virtual AstType* findType(const std::string& name);

	virtual CodeGen* makeCall(
		llvm::LLVMContext& c,
		const std::string& name,
		std::vector<std::pair<std::string, CodeGen*>>& arguments,
		CodeGen* object
	);
public:
	std::string path;
	std::string name;
	static int serial;
	// CodeGen* thisGen();
public:
	llvm::StructType* _type = nullptr;
	std::vector<AstFunction*> creators;
	std::map<int, CodeGen*> defaultValues;      // 成员变量默认值
	std::multimap<std::string, AstFunction*>		methds;		// 方法
	std::map<std::string, ClassMemberGen*> memberGens; 
	std::map<std::string, AstType*> templateTypes;
	FunctionInstance* finalize = nullptr;	// 析构函数
protected:
	CodeGen* findSymbolValue(const std::string& name, bool recursive);
	// virtual CallGen* makeCall(AstContext*, CodeGen* value, const std::string& name, std::vector<std::pair<std::string, CodeGen*>>& arguments);
private:
	CodeGen* _thisGen = nullptr;
};
