#include "stdafx.h"
#include "AstPackage.h"
#include "AstContext.h"
#include "CodeGenerate/CodeGen.h"
#include "AstImport.h"
								   
using namespace llvm;
extern LLVMContext llvmContext;

void AstPackage::draw(std::ostream & os) {
	os << "package[label=\"package " << name << "\"]" << std::endl;

	for (auto i : lines) {
		os <<  " package -> " << i->nodeId << std::endl;
		i->draw(os);
	}
}

AstContext* AstPackage::preprocessor(llvm::Module *m)
{
	if (!names.empty()) {
		for (auto i : names) {
			name += i + ".";
		}
		name.erase(name.size() - 1);
	}

	auto *block=new AstContext(m);
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
