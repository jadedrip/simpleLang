#pragma once
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <map>
#include <sstream>
#include <llvm/IR/IRBuilder.h>

template< typename T, typename K >
inline T* getMapValue(const std::map<K, T*>& map, const K&name) {
	auto i=map.find(name);
	return i == map.end() ? nullptr : i->second;
}

template< typename T >
inline T* getMapValue(const std::unordered_map<std::string, T*>& map, const std::string&name) {
	auto i = map.find(name);
	return i == map.end() ? nullptr : i->second;
}

/// 把操作符转换成字符串
std::string operator_to_str(int op);
/// 把操作符转换成英文
std::string operator_to_word(int op);
/// 返回可读
std::string getReadable(const llvm::Type *);

/// 返回压缩的类型文本
std::string getCompression(const llvm::Type* type);

class AstNode;
class BlockGen;
class AstContext;
BlockGen* makeCodeGenList(AstContext * parent, std::vector<AstNode*>& lines);

template< typename T, typename B >
inline bool isType(B *p) {
	T* x=dynamic_cast<T*>(p);
	return x;
}

inline bool instanceOf(llvm::Type* a, llvm::Type* b)
{
	assert(a && b && "Can't be null");
	return a->getTypeID() == b->getTypeID();
}

extern thread_local llvm::LLVMContext llvmContext;
template< typename T >
inline llvm::Value* toLLValue(T v);

template< typename T >
inline llvm::Value* toLLValue(T* v)
{
	return v;
}

inline llvm::Value* toLLValue(llvm::Type* type)
{
	return llvm::ConstantInt::getNullValue(type);
}

inline llvm::Value* toLLValue(std::nullptr_t v)
{
	auto* type = llvm::IntegerType::get(llvmContext, 32);
	return llvm::ConstantInt::getNullValue(type);
}

inline llvm::Value* toLLValue(llvm::Value* v)
{
	return v ? v : toLLValue(nullptr);
}

inline llvm::Value* toLLValue(int16_t v)
{
	auto *type = llvm::IntegerType::get(llvmContext, 16);
	return llvm::ConstantInt::get(type, v);
}

inline llvm::Value* toLLValue(int32_t v)
{
	auto *type = llvm::IntegerType::get(llvmContext, 32);
	return llvm::ConstantInt::get(type, v);
}

inline llvm::Value* toLLValue(int64_t v)
{
	auto *type = llvm::IntegerType::get(llvmContext, 32);
	return llvm::ConstantInt::get(type, v);
}

inline llvm::Value* toLLValue(uint64_t v)
{
	auto *type = llvm::IntegerType::get(llvmContext, 32);
	return llvm::ConstantInt::get(type, v, true);
}

inline char getCode(short m) {
	if (m < 10) return m + '0';
	if (m < 36) return m - 10 + 'A';
	return m - 36 + 'a';
}

inline std::string i2hexString(uint64_t i) {
	static const char* n = "0123456789abcdefghij";
	std::string s;
	while (i > 0) {
		s.push_back(n[i % 0xF]);
		i >>= 8;
	}
	return s;
}
