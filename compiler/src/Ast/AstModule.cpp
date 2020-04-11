#include "stdafx.h"
#include "AstModule.h"
#include "AstContext.h"
#include "CodeGenerate/CodeGen.h"
#include "AstImport.h"
#include "AstClass.h"
#include "modules.h"

using namespace llvm;
extern LLVMContext llvmContext;

void AstModule::draw(std::ostream & os) {
	os << "package[label=\"package " << name << "\"]" << std::endl;

	for (auto i : lines) {
		os <<  " package -> " << i->nodeId << std::endl;
		i->draw(os);
	}
}

ClassInstanceType* stringCls = nullptr;
AstContext* AstModule::preprocessor(llvm::Module *m)
{
	if (!names.empty()) {
		for (auto i : names) {
			name  += i + ".";
		}
		name.erase(name.size() - 1);
	}

	AstContext* block = new AstContext(m);
	if (name != "si") { // 默认读入 String
		AstClass* p=AstImport::loadClass("si", "String");
		assert(p);
		block->setCompiledClass("struct.si_String", p->generated);
		block->setClass("String", p);
	}
	
	block->module = m;
	block->pathName = name;
	for (auto a : imports) {
		a->makeGen(block);
	}

	for (auto i : lines) {
		auto *p=i->makeGen(block);
		if (p) _gens.push_back(p);
	}
	return block;
}

void AstModule::generateCode(Module *m)
{
	Type *type = Type::getVoidTy(llvmContext);

	// 创建包初始化函数
	FunctionType *FT = FunctionType::get(type, false);
	_func = Function::Create(FT, Function::ExternalLinkage, "main", m);
	auto alloc = BasicBlock::Create(llvmContext, name, _func);
	auto basicBlock = BasicBlock::Create(llvmContext, name, _func);
	auto deallocate = BasicBlock::Create(llvmContext, "dealloc", _func);

	// 写进入模块
	IRBuilder<> builder(basicBlock);
	Generater generater = { m, _func,  &builder, deallocate };
	for (auto i : _gens) {
		i->generate(generater);
	}
	// 写退出模块
	builder.CreateBr(deallocate);

	builder.SetInsertPoint(alloc);
	builder.CreateBr(basicBlock);
	builder.SetInsertPoint(deallocate);
	builder.CreateRetVoid();
}
