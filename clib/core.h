#include <stdint.h>

// DO NOT USE BOM
#ifdef __cplusplus
extern "C" {
#endif
	extern void* createObject(uint64_t objectSize, uint32_t typeId);
	extern void freeObject(void* object);
	extern long referenceIncrease(void* object);

	extern void* createArray(uint32_t objectSize, uint32_t typeId, uint32_t length);
#ifdef __cplusplus
}
#endif
