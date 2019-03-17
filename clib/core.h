#include <stdint.h>

// DO NOT USE BOM
#ifdef __cplusplus
extern "C" {
#endif
	void* createObject(uint64_t objectSize, uint32_t typeId);
	void freeObject(void* object);
	long referenceIncrease(void* object);
	void* createArray(uint32_t objectSize, uint32_t typeId, uint32_t length);
#ifdef __cplusplus
}
#endif
