#include <map>
#include <llvm/IR/Function.h>
#include <string>
#include <vector>

llvm::Module* loadCHeader(const std::string& package_name, const std::string& filename, const std::vector<std::string>& includes);
