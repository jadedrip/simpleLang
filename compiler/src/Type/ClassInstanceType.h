#pragma once
#include "AstType.h"
#include "AstContext.h"
#include "../CodeGenerate/CallGen.h"
#include "../CodeGenerate/ClassMemberGen.h"

class ClassContext;
class FunctionInstance;
													
class ClassInstanceType : public AstType
{
	friend class AstClass;
public:
	static ClassInstanceType* findByName(const std::string& name);
public:
	ClassInstanceType(const std::string& path, const std::string& name);
public:
	virtual std::string uniqueName();
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);
	ClassContext* makeContext(AstContext* parent);
	/// 查询成员对象
	virtual ClassMemberGen* getMember(CodeGen* object, const std::string& name);
	virtual CallGen * makeCall(AstContext*, CodeGen * value, const std::string & name, std::vector<std::pair<std::string, CodeGen*>>& arguments);
	CodeGen* newObject(AstContext* parent, std::vector<std::pair<std::string, CodeGen*> >& );
public:
	std::string path;
	std::string name;
	static int serial;
	CodeGen* thisGen();
public:
	llvm::StructType* _type = nullptr;
	std::vector<AstFunction*> creators;
	std::map<int, CodeGen*> defaultValues;      // 成员变量默认值
	std::multimap<std::string, AstFunction*>		methds;		// 方法
	std::map<std::string, ClassMemberGen*> memberGens; 
private:
	AstContext* _context; //  
	CodeGen* _thisGen = nullptr;
};
