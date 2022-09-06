#include "stdafx.h"
#include "FileGen.h"

using namespace llvm;

extern LLVMContext llvmContext;
llvm::Function* FileGen::generateCode(llvm::Module* m) {
	 m->getContext();
	Type* type = Type::getVoidTy(llvmContext);

	// 创建包初始化函数
	FunctionType* FT = FunctionType::get(type, false);
	auto main_func = Function::Create(FT, Function::ExternalLinkage, "main", m);
	auto alloc = BasicBlock::Create(llvmContext, "main_alloc", main_func);
	auto basicBlock = BasicBlock::Create(llvmContext, "main_basic", main_func);
	auto deallocate = BasicBlock::Create(llvmContext, "dealloc", main_func);

	// 写进入模块
	IRBuilder<> builder(basicBlock);
	Generater generater = { m, main_func,  &builder, deallocate };
	for (auto i : generates) {
		i->generate(generater);
	}
	// 写退出模块
	builder.CreateBr(deallocate);

	builder.SetInsertPoint(alloc);
	builder.CreateBr(basicBlock);
	builder.SetInsertPoint(deallocate);
	builder.CreateRetVoid();

	return main_func;
}