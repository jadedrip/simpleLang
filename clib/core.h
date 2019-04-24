#include <stdint.h>

// DO NOT USE BOM
#ifdef __cplusplus
extern "C" {
#endif
	// 定义析构函数
	typedef void (*destructor)(void* object);

	void* createObject(uint32_t objectSize, uint64_t typeId);
	void freeObject(void* object, destructor func);
	long referenceIncrease(void* object);
	void* createArray(uint32_t objectSize, uint64_t typeId, uint32_t length);
	void* arrayIndex(byte* ptr, uint32_t objectSize);
#ifdef __cplusplus
}
#endif
