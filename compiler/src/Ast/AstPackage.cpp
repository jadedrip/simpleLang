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


	std::unique_ptr<clang::CompilerInstance> Compiler(new clang::CompilerInstance());
	Compiler->createDiagnostics(); 
	std::shared_ptr<clang::TargetOptions> TargetOptionsInstance(new clang::TargetOptions()); 
	TargetOptionsInstance->Triple = sys::getProcessTriple();
	 Compiler->setTarget(clang::TargetInfo::CreateTargetInfo(Compiler->getDiagnostics(), TargetOptionsInstance)); 
	 Compiler->createFileManager(); Compiler->createSourceManager(Compiler->getFileManager()); 
	 Compiler->createPreprocessor(clang::TU_Complete); Compiler->createASTContext();
	 clang::ASTContext& ASTContextInstance = Compiler->getASTContext(); 
	 clang::IdentifierTable& Identifiers = Compiler->getPreprocessor().getIdentifierTable(); 
	 // AST building 
	 // TranslationUnitDecl 
	 clang::TranslationUnitDecl *TranslationUnitDeclInstance = ASTContextInstance.getTranslationUnitDecl(); 


	if (name != "si") { // 默认读入 String
		AstClass* p=AstImport::loadClass("si", "String");
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

void AstPackage::generateCode(Module *m)
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
