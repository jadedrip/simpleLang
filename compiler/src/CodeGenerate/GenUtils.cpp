#include "stdafx.h"
#include "GenUtils.h"

bool isString(llvm::Type* type)
{
    if (!type->isStructTy()) return false;
    return type->getStructName() == "struct.String__sl";
}
