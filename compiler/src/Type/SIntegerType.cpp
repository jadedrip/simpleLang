#include "stdafx.h"
#include "SIntegerType.h"

using namespace llvm;
SIntegerType::SIntegerType(int bitWidth, bool isUnsigned)
	: AstType(AstType::IntegerTyID)
{
	this->bitWidth = bitWidth;
	this->isUnsigned = isUnsigned;

	switch (bitWidth) {
	case 1:
		name = "boolean";
		this->isUnsigned = true;
		break;
	case 8:
		name = "byte";
		this->isUnsigned = true;
		break;
	case 16:
		name = isUnsigned ? "ushort" : "short";
		break;
	case 32:
		name = isUnsigned ? "uint" : "int";
		break;
	case 64:
		name = isUnsigned ? "ulong" : "long";
		break;
	default:
		name = "unknown";
		break;
	}
}

SIntegerType* sBoolean = nullptr;
SIntegerType* sByte = nullptr;
SIntegerType* sShort = nullptr;
SIntegerType* uShort = nullptr;
SIntegerType* sInteger = nullptr;
SIntegerType* uInteger = nullptr;
SIntegerType* sLong = nullptr;
SIntegerType* uLong = nullptr;

SIntegerType * SIntegerType::get(int bitWidth, bool isUnsigned)
{
	switch (bitWidth)
	{
	case 1:
		if (!sBoolean) sBoolean = new SIntegerType(1, true);
		return sBoolean;
	case 8:
		if (!sByte) sByte = new SIntegerType(8, true);
		return sByte;
	case 16:
		if (isUnsigned) {
			if (!uShort) uShort = new SIntegerType(16, true);
			return uShort;
		}
		else {
			if (!sShort) sShort = new SIntegerType(16, false);
			return sShort;
		}
	case 32:
		if (isUnsigned) {
			if (!uInteger) uInteger = new SIntegerType(32, true);
			return uInteger;
		}
		else {
			if (!sInteger) sInteger = new SIntegerType(32, false);
			return sInteger;
		}
	case 64:
		if (isUnsigned) {
			if (!uLong) uLong = new SIntegerType(64, true);
			return uLong;
		}
		else {
			if (!sLong) sLong = new SIntegerType(64, false);
			return sLong;
		}
	default:
		return nullptr;
	}
}

llvm::Type * SIntegerType::llvmType(llvm::LLVMContext & context)
{
	return IntegerType::get(context, bitWidth);
}

std::string SIntegerType::uniqueName() {
	switch (bitWidth) {
		case 1:
			return "_N"; // bool
		case 8:
			return isUnsigned ? "E" : "D";
		case 16:
			return  isUnsigned ? "G" : "F";
		case 32:
			return  isUnsigned ? "I": "H";
		case 64:
			return  isUnsigned ? "K" : "J";
		default:
			break;
	}
	return name;
}

