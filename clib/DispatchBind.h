#pragma once
#include "Coroutine.h"

#ifdef __cplusplus 
extern "C" {
#endif // 

void DispatchCreateCoroutine(Coroutine* co, SiGoFunction *func);
int64_t DispatchGetCoroutineParam(size_t index);
void DispatchYield();
Coroutine* DispatchGetCurrent();
Coroutine* DispatchSetSuspend(Chan*, long waiting);

#ifdef __cplusplus 
}
#endif // 