#pragma once
#include "Coroutine.h"

#ifdef __cplusplus 
extern "C" {
#endif // 

void DispatchCreateCoroutine(Coroutine* co, SiGoFunction *func);
void DispatchYield();
Coroutine* DispatchGetCurrent();
Coroutine* DispatchSetSuspend(long waiting);

#ifdef __cplusplus 
}
#endif // 