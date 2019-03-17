#include "stdafx.h"
#include "Coroutine.h"
#include "DispatchBind.h"

void si_CoroutineCreate(Coroutine* co, SiGoFunction *func)
{
	DispatchCreateCoroutine(co, func);
}

void si_YieldCoroutine()
{
	DispatchYield();
}

void* si_AwaitCoroutine(Chan *chan, int64_t waiting)
{
	chan->co = DispatchSetSuspend(waiting);
	DispatchYield();
	return chan->co->data;
}

void* si_Coroutine_getData(Coroutine* co)
{
	return co->data;
}

void* si_GetCurrentCoroutineData()
{
	return DispatchGetCurrent()->data;
}

void si_Chan_BRACKETS(Chan* chan, void* data)
{
	Coroutine* co = chan->co;
	if (co) {
		if (co->status == COROUTINE_SUSPEND) {
			co->data = data;
			co->status = COROUTINE_READY;
		} 
	} 
}
