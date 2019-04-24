#include <map>
#include <llvm/IR/Function.h>
#include <string>

llvm::Module* loadCHeader(const std::string& package_name, const std::string& filename);
