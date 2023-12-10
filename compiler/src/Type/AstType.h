#pragma once
#include <string>

/// 定义类型
class AstType {
public:
  std::string name;
  bool nullable = false;
  bool isSigned = true;

  enum SiTypeId // 定义类型的 ID
  {
    AutoTyId = 0,
    VoidTyID = 1,       ///<  0: type with no size
    NullTyId,
    
    FloatTyID,   ///<  32-bit floating point type
    DoubleTyID,  ///<  3: 64-bit floating point type

    BooleanTyId,      /// 1-bit Integer
    ByteTyId,         /// 8-bit Integer
    Int16TyId,        /// 16-bit Integer
    Int32TyId,        /// 32-bit Integer
    Int64TyId,        /// 64-bit Integer

    FunctionTyID,     ///< Functions
    ClassTyID,        ///< Structures

    CharactersTyId,   // 字符串
    InterfaceTyId,
    StaticTrueTyId,
    StaticFalseTyId,  // 用来静态推断用
    TupleTyId
  };

  inline bool is(SiTypeId id) const { return _type == id; }

  /// @brief 是否整数
  inline bool isInteger() const {
    return _type >= ByteTyId && _type < Int64TyId;
  }
  inline bool isFloatOrDouble() const {
    return _type == FloatTyID || _type == DoubleTyID;
  }
  inline bool isClassOrTuple() const {
    return _type == ClassTyID || _type == TupleTyId;
  }
  inline bool isNumber() const { return isInteger() || isFloatOrDouble(); }
  inline bool equal(AstType* other){
	if( _type != other->_type) return false;
	return (_type == ClassTyID) ? name==other->name : true;
  }
  static AstType *staticTrue;
  static AstType *staticFalse;
  static AstType *stringType;
  static AstType *anyType;
  static AstType *voidType;
  static AstType *floatType;
  static AstType *doubleType;
  static AstType *nullType;
  static AstType *booleanType;
  static AstType *byteType;
  static AstType *int16Type;
  static AstType *int32Type;
  static AstType *int64Type;
  static AstType *ubyteType;
  static AstType *uint16Type;
  static AstType *uint32Type;
  static AstType *uint64Type;

  AstType(SiTypeId type = AutoTyId, bool isSigned=true);

  virtual SiTypeId type() { return _type; }

  /// 返回唯一的短名称（将用于重载函数的命名）
  virtual std::string uniqueName();
  virtual size_t hashCode();

  uint32_t typeId() const;

  virtual ~AstType() {}

  template <typename Iterator>
  static std::string uniqueName(Iterator begin, Iterator end) {
    std::string name;
    for (auto i = begin; i != end; i++) {
      AstType *type = *i;
      name += type->uniqueName();
    }
    // TODO: 如果名称过长，hash 下
    return name;
  }

protected:
  size_t hash(size_t o, size_t v);
  const SiTypeId _type;
  uint32_t _id;
};
