#pragma once
#include "../Ast/AstNode.h"
#include <llvm/IR/Type.h>
					
/// 定义类型
class AstType {
public:
	std::string name;
	bool nullable = false;

	enum SiTypeId // 扩展 llvm::Type::TypeID
	{
		VoidTyID = 0,    ///<  0: type with no size
		HalfTyID,        ///<  1: 16-bit floating point type
		FloatTyID,       ///<  2: 32-bit floating point type
		DoubleTyID,      ///<  3: 64-bit floating point type
		X86_FP80TyID,    ///<  4: 80-bit floating point type (X87)
		FP128TyID,       ///<  5: 128-bit floating point type (112-bit mantissa)
		PPC_FP128TyID,   ///<  6: 128-bit floating point type (two 64-bits, PowerPC)
		LabelTyID,       ///<  7: Labels
		MetadataTyID,    ///<  8: Metadata
		X86_MMXTyID,     ///<  9: MMX vectors (64 bits, X86 specific)
		TokenTyID,       ///< 10: Tokens

		// Derived types... see DerivedTypes.h file.
		// Make sure FirstDerivedTyID stays up to date!
		IntegerTyID,     ///< 11: Arbitrary bit width integers
		FunctionTyID,    ///< 12: Functions
		StructTyID,      ///< 13: Structures
		ArrayTyID,       ///< 14: Arrays
		PointerTyID,     ///< 15: Pointers
		VectorTyID,       ///< 16: SIMD 'packed' format, or other vector type

		AutoTyId = 20,
		CharactersTyId,	// character string 
		AnyTyId,
		InterfaceTyId,
		StaticTrueTyId,
		StaticFalseTyId,	// 用来静态推断用
		TupleTyId,
		NullTyId
	};

	inline bool isAuto() const { return _type == AutoTyId; }
	inline bool isInteger() const { return _type == IntegerTyID; }
	inline bool isFloatOrDouble() const { return _type == FloatTyID || _type == DoubleTyID; }
	inline bool isClass() const { return _type == StructTyID || _type == TupleTyId; }
	inline bool isNumber() const { return isInteger() || isFloatOrDouble(); }
	inline bool isFloat() const { return _type == FloatTyID; }
	inline bool isDouble() const { return _type == DoubleTyID; }
	inline bool isString() const { return _type == CharactersTyId; }

	static AstType* staticTrue;
	static AstType* staticFalse;
	static AstType* stringType;
	static AstType* anyType;
	static AstType* voidType;
	static AstType* floatType;
	static AstType* doubleType;
	static AstType* nullType;

	AstType(SiTypeId type = AutoTyId);

	virtual SiTypeId type() { return _type; }

	/// 判断本类型是否指定类型，或是从指定类型继承的
	virtual bool instanceOf(AstType* p);

	/// 返回唯一的短名称（将用于重载函数的命名）
	virtual std::string uniqueName();
	virtual size_t hashCode();

	virtual llvm::Type* llvmType(llvm::LLVMContext& context);

	uint32_t typeId() const;

	virtual CodeGen* malloc(AstContext* context);

	virtual ~AstType() {}
protected:
	size_t hash(size_t o, size_t v);
	const SiTypeId _type;
	uint32_t _id;
};
