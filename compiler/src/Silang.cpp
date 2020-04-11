// Silang.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include "Ast/AstNode.h"
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/Signals.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/ExecutionEngine/JITEventListener.h>
#include <llvm/IR/AssemblyAnnotationWriter.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/ExecutionEngine/JITSymbol.h>
#include <llvm/Support/PrettyStackTrace.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include "si_c.h"
#include "Ast/AstModule.h"
#include "modules.h"
#include "utility.h"
#include "CompilerOptions.h"

extern int yyparse(void);
extern FILE *yyin, *yyout;
extern int yydebug, yylineno;

bool parse() {
	try {
		yydebug = 0;
		return 0 == yyparse(); /* start the analysis*/
	}
	catch (std::exception e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return false;
}

using namespace llvm;
LLVMContext llvmContext;
std::unique_ptr<Module> module;

AstModule* currentPackage = new AstModule();
ExecutionEngine* buildEngine(std::unique_ptr<Module> Owner);

// 源文件是否 utf8 的
bool utf8File = false;

extern RTDyldMemoryManager *RTDyldMM;
void execute(char * const *envp){
	char *error = NULL;

	std::string ErrStr;
	llvm::StringRef MCPU = llvm::sys::getHostCPUName();

	std::cout << "MCPU: " << MCPU.str() << std::endl;

	// module->setTargetTriple("x86_64-pc-windows-msvc");
	Function *mainFunction = currentPackage->getFunc();

	//auto iter=module->functions();
	//for( auto i=iter.begin(); i!=iter.end(); i++){
	//	std::cout << i->getName().str() << std::endl;
	//}
	raw_os_ostream os(std::clog);
	//
	// Execute the program
	//
	llvm::ExecutionEngine *EE = buildEngine(std::move(module));
	if (EE) {

		auto target = EE->getTargetMachine();

		// The following functions have no effect if their respective profiling
		// support wasn't enabled in the build configuration.
		EE->RegisterJITEventListener(
			JITEventListener::createOProfileJITEventListener());
		EE->RegisterJITEventListener(
			JITEventListener::createIntelJITEventListener());

		EE->DisableLazyCompilation(false);
		CLangModule::moveAll(EE);
		// Give MCJIT a chance to apply relocations and set page permissions.
		EE->finalizeObject();
		// EE->runStaticConstructorsDestructors(false);

		//auto *p=EE->FindFunctionNamed("si_printHello");
		//auto v=EE->getFunctionAddress("si_printHello");
		//assert(v);
		//os << "\r\n ***** \r\n";
		//p->print(os);
		//os << "\r\n ***** \r\n";
		//os.flush();
		std::vector<std::string> noargs;
		EE->runFunctionAsMain(mainFunction, noargs, envp);

		// Clear instruction cache before code will be executed.
		if (RTDyldMM)
			static_cast<SectionMemoryManager*>(RTDyldMM)->invalidateInstructionCache(
			);

		// Run static destructors.
		// EE->runStaticConstructorsDestructors(true);
	}
	else
		std::cerr << "无法创建 JIT 引擎: " << ErrStr << std::endl;
	CLangModule::shutdown();
}

using namespace llvm;
namespace stdfs = std::filesystem;

int main(int argc, char* argv[],  char * const *envp)
{
	PrettyStackTraceProgram X(argc, argv);

	atexit(llvm_shutdown); // Call llvm_shutdown() on exit.

	sys::PrintStackTraceOnErrorSignal(argv[0]);
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();

	if (sys::DynamicLibrary::LoadLibraryPermanently(nullptr)) {
		errs() << "Error loading program symbols.\n";
		return -1;
	}
	std::string err;
	//if (sys::DynamicLibrary::LoadLibraryPermanently("msvcp_win.dll", &err)) {
	//	errs() << "Error loading: "<< err<< "\n";
	//	// return -1;
	//}


	std::cout << "Triple: " << ::sys::getProcessTriple() << std::endl;
	std::cout << "HostCpu: " << ::sys::getHostCPUName().str() << std::endl;

	CompilerOptions::instance().triple = ::sys::getProcessTriple();

	llvm::Triple triple;
	std::cout << "OsName: " << triple.getOSName().str() << std::endl;

	auto *m = new Module("TOP", llvmContext);
	module.reset(m);

	CLangModule::initialize(::sys::getProcessTriple());

	bool b;
	if (argc > 1) {
		yylineno = 0;
		yyin = fopen(argv[1], "r"); /* 首先打开要被处理的文件（参数1）yyin是lex默认的文件输入指针，设置了则不处理控制台输入 */
		if (!yyin) {
			std::cerr << "无法打开文件：" << argv[1] << std::endl;
			return -1;
		}
		b = parse();
		fclose(yyin);
	}
	else {
		b = parse();
	}

	if (b) {
		try {
			currentPackage->preprocessor(m);
		}
		catch (std::runtime_error e) {
			std::cerr << "发生异常：" << e.what() << std::endl;
			module.reset();
			CLangModule::shutdown();
			return -1;
		}

		std::ofstream of("out.gv");
		of << "digraph ast {" << std::endl;
		of << "rankdir=LR;" << std::endl;
		currentPackage->draw(of);
		of << "}";
		of.close();

		currentPackage->generateCode(m);
	
		{
			std::ofstream file("out.ll");
			llvm::raw_os_ostream os(file);

			module->print(os, nullptr, false, true);
			os.flush();
			file.close();
		}

		// system("start out.gv");

		llvm::SMDiagnostic error;
		execute(envp);
		// system("lli -force-interpreter out.ll");
		// clang -lx64\Debug\clib.lib -x ir -o out.exe -g out.ll lib\si\String.ll lib\si\core.ll lib\si\Coroutine.ll
	} else {
		CLangModule::shutdown();

		auto * m= module.release();
		delete m;
	}
	return 0;
}

