#include "stdafx.h"
#include "AstModule.h"
#include "AstContext.h"
#include "CodeGenerate/CodeGen.h"
#include "AstImport.h"
#include "AstClass.h"
#include "modules.h"

using namespace llvm;

void AstModule::draw(std::ostream & os) {
	os << "package[label=\"package " << name << "\"]" << std::endl;

	for (auto i : lines) {
		os <<  " package -> " << i->nodeId << std::endl;
		i->draw(os);
	}
}

ClassInstanceType* stringCls = nullptr;
FileGen* AstModule::preprocessor(AstContext* context)
{
	if (!names.empty()) {
		for (auto i : names) {
			name  += i + ".";
		}
		name.erase(name.size() - 1);
	}

	//if (name != "sl") { // 默认读入 String
	//	AstClass* p=AstImport::loadClass("sl", "String");
	//	assert(p);
	//	block->setCompiledClass("struct.si_String", p->generated);
	//	block->setClass("String", p);
	//}
	
	for (auto a : imports) {
		a->makeGen(context);
	}

	auto list=new FileGen();
	for (auto i : lines) {
		auto *p=i->makeGen(context);
		if (p) {
			list->generates.push_back(p);
		}
	}
}
