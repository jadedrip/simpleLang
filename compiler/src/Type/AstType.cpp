#include "stdafx.h"
#include "AstType.h"
#include "AutoType.h"

AstType* AstType::staticTrue = new AstType(AstType::StaticTrueTyId);
AstType* AstType::staticFalse = new AstType(AstType::StaticFalseTyId);
AstType* AstType::stringType = new AstType(AstType::CharactersTyId);
AstType* AstType::anyType = new AstType(AstType::AnyTyId);
AstType* AstType::voidType = new AstType(AstType::VoidTyID);
AstType* AstType::floatType = new AstType(AstType::FloatTyID);
AstType* AstType::doubleType = new AstType(AstType::DoubleTyID);
AstType* AstType::nullType = new AstType(AstType::NullTyId);

static uint32_t typeIdSeed = 0;

AstType::AstType(SiTypeId t) : _type(t) {
	_id = typeIdSeed++;		// TODO: thread safe
	switch (t)
	{
	case FloatTyID:
		name = "float";
		break;
	case DoubleTyID:
		name = "double";
		break;
	case AstType::CharactersTyId:
		name = "characters";
		break;
	case AstType::AnyTyId:
		name = "any";
		break;
	case AstType::VoidTyID:
		name = "void";
		break;
	case AstType::InterfaceTyId:
		name = "interface";
		break;
	case AstType::AutoTyId:
		name = "var";
		break;
	case AstType::StaticTrueTyId:
		name = "True";
		break;
	case AstType::StaticFalseTyId:
		name = "False";
		break;
	}
}

/// 判断本类型是否指定类型，或是从指定类型继承的
bool AstType::instanceOf(AstType * p) {	// TODO: 支持继承
	if (this == p || this->hashCode() == p->hashCode())
		return true;
	return (this->inherit ? this->inherit->instanceOf(p) : false);
}


/// 返回唯一的名称

std::string AstType::uniqueName() {
	switch (_type) {
		case VoidTyID:
			return "X";
		case FloatTyID:
			return "M";
		case DoubleTyID:
			return "N";
		default:
			break;
	}
	return "A"; 
}

size_t AstType::hashCode()
{
	return type();
}

llvm::Type * AstType::llvmType(llvm::LLVMContext & context)
{
	switch (type())
	{
	case VoidTyID:
		return llvm::Type::getVoidTy(context);
	default:
		break;
	}
	return nullptr;
}

uint32_t AstType::typeId() const
{
	return _id;
}

CodeGen * AstType::malloc(AstContext * context) { 
	return nullptr; 
}

size_t AstType::hash(size_t h, size_t v)
{
	h *= 16777619;
	h ^= v;
	return h;
}
