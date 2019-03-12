#include "stdafx.h"
#include "AstPackage.h"
#include "AstContext.h"
#include "CodeGenerate/CodeGen.h"
#include "AstImport.h"
#include "AstClass.h"
#include "modules.h"

using namespace llvm;
extern LLVMContext llvmContext;

void AstPackage::draw(std::ostream & os) {
	os << "package[label=\"package " << name << "\"]" << std::endl;

	for (auto i : lines) {
		os <<  " package -> " << i->nodeId << std::endl;
		i->draw(os);
	}
}

ClassInstanceType* stringCls = nullptr;
AstContext* AstPackage::preprocessor(llvm::Module *m)
{
	if (!names.empty()) {
		for (auto i : names) {
			name += i + ".";
		}
		name.erase(name.size() - 1);
	}

	AstContext* block = new AstContext(m);
	if (name != "si") { // 默认读入 String
		AstClass* p=AstImport::loadClass("si", "String");
		block->setCompiledClass("struct.si_String", p->generated);

		//auto *mm=CLangModule::loadLLFile("lib\\si\\String.ll");

		//auto *si = CLangModule::loadSiFile("lib\\si\\String.si", "si", mm);
		//auto *s = si->findClass("String");
		//if(s) block->setClass("String", s);
		//auto *x = si->findCompiledClass("struct.si_String");
		//if(x) block->setCompiledClass("struct.si_String", x);
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

void AstPackage::generateCode(Module *m)
{
	Type *type = Type::getVoidTy(llvmContext);

	// 创建包初始化函数
	FunctionType *FT = FunctionType::get(type, false);
	_func = Function::Create(FT, Function::ExternalLinkage, "_P_" + name, m);
	auto alloc = BasicBlock::Create(llvmContext, name, _func);
	auto basicBlock = BasicBlock::Create(llvmContext, name, _func);

	IRBuilder<> builder(basicBlock);
	for (auto i : _gens) {
		i->generate(m, _func, builder);
	}
	builder.CreateRetVoid();

	builder.SetInsertPoint(alloc);
	builder.CreateBr(basicBlock);
}
