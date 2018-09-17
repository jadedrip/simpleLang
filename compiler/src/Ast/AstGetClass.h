#pragma once
#include "AstNode.h"
#include "AstClass.h"

/* ªÒ»°¿‡ */
class AstGetClass : public AstType {
public:
	AstClass* toClass = nullptr;
};
