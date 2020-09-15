#include "stdafx.h"
#include <sstream>
#include "CodeGenerate/BlockGen.h"
#include "utility.h"
#include "Ast/AstNode.h"
#include "AstContext.h"
#include "token.h"

using namespace std;
using namespace llvm;

/// 把操作符转换成字符串
std::string operator_to_str(int op) {
	switch (op)
	{
	case LEFTMOVE:
		return "<<";
	case RIGHTMOVE:
		return ">>";
	case URIGHTMOVE:
		return ">>>";
	case LEQ:
		return "<=";
	case REQ:
		return ">=";
	case RGO:
		return "=>";
	case EQ:
		return "==";
	case AEQ:
		return ":=";
	case NOEQ:
		return "!=";
	case OR:
		return "||";
	case AND:
		return "&&";
	case INC:
		return "++";
	case DEC:
		return "--";
	case ARRAY:
		return "->";
	case ISOPT:
		return "is";
	default:
		return std::string(1, (char)op);
	}
}

std::string operator_to_word(int op)
{
	switch (op) {
	case LEFTMOVE:
		return "LEFTMOVE";
	case RIGHTMOVE:
		return "RIGHTMOVE";
	case URIGHTMOVE:
		return "URIGHTMOVE";
	case LEQ:
		return "LEQ";
	case REQ:
		return "REQ";
	case RGO:
		return "RGO";
	case EQ:
		return "EQ";
	case AEQ:
		return "AEQ";
	case NOEQ:
		return "NEQ";
	case OR:
		return "OR";
	case AND:
		return "AND";
	case INC:
		return "INC";
	case DEC:
		return "DEC";
	case ARRAY:
		return "ARRAY";
	case ISOPT:
		return "IS";
	case '+':
		return "PLUS";
	case '-':
		return "MINUS";
	case '*':
		return "MCL";
	case '/':
		return "DIV";
	default:
		throw std::runtime_error("Unknown operator:" + (char)(op));
	}
}


std::string getReadable(llvm::Type *type)
{
	if (type->isVoidTy()) {
		return "V";
	}

	if (type->isStructTy()) {
		string n = type->getStructName();
		if (n.substr(0, 7) == "struct.")
			n = n.substr(7);
		return n;
	}

	if (type->isIntegerTy()) {
		return "I" + to_string(type->getIntegerBitWidth());
	}
	if (type->isFloatingPointTy()) {
		return "M";
	}
	if (type->isDoubleTy()) {
		return "N";
	}
	if (type->isPointerTy()) {
		return "P" + getReadable(type->getPointerElementType());
	}

	std::ostringstream ss;
	if (type->isFunctionTy()) {
		ss << "F";
		auto *tp=dyn_cast<FunctionType>(type);
		for (auto i = tp->param_begin(); i != tp->param_end(); i++) {
			ss << getReadable(*i);
		}
		ss << "$";
		return ss.str();
	}

	llvm::raw_os_ostream os(ss);
	type->print(os);
		
	throw std::runtime_error("Unknown type" + ss.str());
}

BlockGen * makeCodeGenList(AstContext * parent, std::vector<AstNode*>& lines)
{
	auto x = new BlockGen();
	auto *p = new AstContext(parent);
	for (auto i : lines) {
		auto o=i->makeGen(p);
		x->codes.push_back(o);
	}
	return x;
}

//std::string getReadable(llvm::Type * type)
//{
//	if (type->isIntegerTy()) {
//		return "i" + std::to_string(llvm::dyn_cast<llvm::IntegerType>(type)->getBitWidth());
//	}
//	if (type->isPointerTy()) {
//		return getReadable(type->getPointerElementType()) + "_ptr";
//	}
//	if (type->isStructTy()) {
//		auto * ty = llvm::dyn_cast<llvm::StructType>(type);
//		std::string n = ty->getName().str();
//		return (0 == n.compare(0, 7, "struct.")) ? n.substr(7) : n;
//	}
//	if (type->isArrayTy()) {
//		auto * ty = llvm::dyn_cast<llvm::ArrayType>(type);
//		return getReadable(ty->getElementType()) + "_arr";
//	}
//	return std::to_string(type->getTypeID());
//}
//
