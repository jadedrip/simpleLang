#pragma once
#include <stdint.h>
#include <typeinfo>
#include <vector>
#include <map>
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

inline int64_t hex2int( const char* str, int length ) {
	if (length < 3) throw std::bad_cast();
	if ('0' != str[0] && 'x' != str[1]) throw std::bad_cast();
	int64_t v = 0;
	for (int i = 2; i < length; ++i) {
		v = v << 4;
		char c = str[i];
		if (c >= 'a' && c <= 'f')
			v |= c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			v |= c - 'A' + 10;
		else if (c >= '0' && c <= '9')
			v |= c - '0';
		else
			throw std::bad_cast();
	}
	return v;
}

/// 把操作符转换成字符串
std::string operator_to_str(int op);
/// 把操作符转换成英文
std::string operator_to_word(int op);

/// 转换成布尔
llvm::Value* int_to_bool(llvm::IRBuilder<>& builder, llvm::Value* v);

std::string getReadable(llvm::Type *);

class AstNode;
struct Parameter;

inline std::string i2hexString(uint64_t i) {
	static const char * n = "0123456789abcdef";
	std::string s;
	while (i > 0) {
		s.push_back(n[i % 0xF]);
		i >>= 8;
	}
	return s;
}

class AstNode;
class BlockGen;
class AstContext;
BlockGen* makeCodeGenList(AstContext * parent, std::vector<AstNode*>& lines);

template< typename T, typename B >
inline bool isType(B *p) {
	T* x=dynamic_cast<T*>(p);
	return x;
}

template< typename T, typename B, typename F>
inline bool ifIsType(B *p, F f)
{
	T* x = dynamic_cast<T*>(p);
	if (x) f(x);
	return x;
}

// 这个把字符串哈希，并输出小于 6个字符的前缀
inline std::string encodeByHash(const std::string& str) {
	unsigned int hash = 1315423911;

	for( char a : str )
	{
		hash ^= ((hash << 5) + a + (hash >> 2));
	}

	std::string out;
	out.reserve(6);
	// (a-z) 26 + (A-F) 6 = 32
	static const char *codes = "abcedefhijklmnopqrstuvwxyzABCDEF";
	while (hash > 0)
	{
		unsigned int v = hash & 0x17;
		hash = hash >> 6;
		out.push_back(codes[v]);
	}
	return out;
}

inline bool instanceOf(llvm::Type* a, llvm::Type* b)
{
	assert(a && b && "Can't be null");
	return a->getTypeID() == b->getTypeID();
}

extern llvm::LLVMContext llvmContext;
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

inline llvm::Value* toLLValue(llvm::Value* v)
{
	return v;
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

std::string toReadable(llvm::Type* type);
inline std::string toShort(llvm::Type* type)
{
	return toReadable(type);
}

inline llvm::Value* getDefaultValue(llvm::Type* type)
{
	if (type->isIntegerTy()) {
		return llvm::ConstantInt::get(type, 0); 
	} else if (type->isFloatingPointTy() || type->isDoubleTy()) {
		return llvm::ConstantFP::get(type, 0.0);
	} 
	return nullptr;
}