#include "stdafx.h"
#include "AstType.h"

AstType *AstType::staticTrue = new AstType(AstType::StaticTrueTyId);
AstType *AstType::staticFalse = new AstType(AstType::StaticFalseTyId);
AstType *AstType::stringType = new AstType(AstType::CharactersTyId);
AstType *AstType::anyType = new AstType(AstType::AnyTyId);
AstType *AstType::voidType = new AstType(AstType::VoidTyID);
AstType *AstType::floatType = new AstType(AstType::FloatTyID);
AstType *AstType::doubleType = new AstType(AstType::DoubleTyID);
AstType *AstType::nullType = new AstType(AstType::NullTyId);
AstType *AstType::booleanType = new AstType(AstType::BooleanTyId);
AstType *AstType::byteType = new AstType(AstType::ByteTyId);
AstType *AstType::int16Type = new AstType(AstType::Int16TyId);
AstType *AstType::int32Type = new AstType(AstType::Int32TyId);
AstType *AstType::int64Type = new AstType(AstType::Int64TyId);
AstType *AstType::ubyteType = new AstType(AstType::ByteTyId, false);
AstType *AstType::uint16Type = new AstType(AstType::Int16TyId, false);
AstType *AstType::uint32Type = new AstType(AstType::Int32TyId, false);
AstType *AstType::uint64Type = new AstType(AstType::Int64TyId, false);

static uint32_t typeIdSeed = 0;

AstType::AstType(SiTypeId t, bool s) : _type(t), isSigned(s) {
  _id = typeIdSeed++; // TODO: thread safe
  switch (t) {
  case FloatTyID:
    name = "float";
    break;
  case DoubleTyID:
    name = "double";
    break;
  case AstType::CharactersTyId:
    name = "characters";
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
  case AstType::NullTyId:
    name = "null";
    break;
  case AstType::BooleanTyId:
    name = "boolean";
    break;
  case AstType::ByteTyId:
    name = s ? "char" : "byte";
    break;
  case AstType::Int16TyId:
    name = s ? "int16" : "uint16";
    break;
  case AstType::Int32TyId:
    name = s ? "int32" : "uint32";
    break;
  case AstType::Int64TyId:
    name = s ? "int64" : "uint64";
    break;
  }
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

size_t AstType::hashCode() { return type(); }

uint32_t AstType::typeId() const { return _id; }

size_t AstType::hash(size_t h, size_t v) {
  h *= 16777619;
  h ^= v;
  return h;
}
