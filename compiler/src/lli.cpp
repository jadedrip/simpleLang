#include "stdafx.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Bitcode/BitcodeReader.h"
#include "llvm/CodeGen/LinkAllCodegenComponents.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/ExecutionEngine/JITEventListener.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/ExecutionEngine/ObjectCache.h"
#include "llvm/ExecutionEngine/Orc/OrcRemoteTargetClient.h"
#include "llvm/ExecutionEngine/OrcMCJITReplacement.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Object/Archive.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/DynamicLibrary.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/Memory.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/PluginLoader.h"
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/Process.h"
#include "llvm/Support/Program.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Instrumentation.h"
#include <cerrno>

using namespace llvm;

#define DEBUG_TYPE "lli"

LLVM_ATTRIBUTE_NORETURN
static void reportError(SMDiagnostic Err, const char *ProgName) {
  Err.print(ProgName, errs());
  exit(1);
}

void addModule( const std::string& InputFile, Module* Mod) {
	std::string CacheName("file:");
	CacheName.append(InputFile);
	Mod->setModuleIdentifier(CacheName);
}

RTDyldMemoryManager *RTDyldMM = nullptr;
ExecutionEngine* buildEngine(std::unique_ptr<Module> Owner) {
  std::string ErrorMsg;
  EngineBuilder builder(std::move(Owner));
  //builder.setMArch(MArch);
  //builder.setMCPU(MCPU);
  //builder.setMAttrs(MAttrs);
  //if (RelocModel.getNumOccurrences())
  //  builder.setRelocationModel(RelocModel);
  //if (CMModel.getNumOccurrences())
  //  builder.setCodeModel(CMModel);
  builder.setErrorStr(&ErrorMsg);
  builder.setEngineKind(EngineKind::JIT);
  builder.setUseOrcMCJITReplacement(false);

  // Enable MCJIT if desired.

      RTDyldMM = new SectionMemoryManager();

    // Deliberately construct a temp std::unique_ptr to pass in. Do not null out
    // RTDyldMM: We still use it below, even though we don't own it.
    builder.setMCJITMemoryManager(
      std::unique_ptr<RTDyldMemoryManager>(RTDyldMM));

  builder.setOptLevel(CodeGenOpt::Default);

  //TargetOptions Options = InitTargetOptionsFromCodeGenFlags();
  //if (FloatABIForCalls != FloatABI::Default)
  //  Options.FloatABIType = FloatABIForCalls;

  //builder.setTargetOptions(Options);

  auto * EE=builder.create();
  if (!EE)
	  std::cerr << ErrorMsg << std::endl;
  //EE->setObjectCache(CacheManager.get());

  //for (unsigned i = 0, e = ExtraObjects.size(); i != e; ++i) {
  //  Expected<object::OwningBinary<object::ObjectFile>> Obj =
  //      object::ObjectFile::createObjectFile(ExtraObjects[i]);
  //  if (!Obj) {
  //    // TODO: Actually report errors helpfully.
  //    consumeError(Obj.takeError());
  //    reportError(Err, argv[0]);
  //  }
  //  object::OwningBinary<object::ObjectFile> &O = Obj.get();
  //  EE->addObjectFile(std::move(O));
 //  }

  return EE;
}
