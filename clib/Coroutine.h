#pragma once
#ifndef __COROUTINE__H__
#define __COROUTINE__H__
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
	enum CoroutineStatus {
		COROUTINE_DEAD = 0,
		COROUTINE_READY = 1,
		COROUTINE_RUNNING = 2,
		COROUTINE_SUSPEND = 3,
		COROUTINE_TIMEOUT = 4
	};

	struct si_Coroutine;
	struct si_Chan {
		void* data;
		volatile char setted;
	};
	typedef struct si_Chan Chan;

	struct si_Coroutine {
		int64_t timeout;		// 超时时间（超时检测用）
		short status;			// 状态 CoroutineStatus
		void* data;				// 返回值
		struct si_Chan* chan;	
		void* lpFiber;
	};

	typedef void* (SiGoFunction)();
	typedef struct si_Coroutine Coroutine;

	// 创建一个协程
	void si_CoroutineCreate(Coroutine*, SiGoFunction*);

	/// 当前协程主动切换 
	void si_YieldCoroutine();

	/// 设置管道
	/// waiting 为0永久等待，否则等待指定时间后将状态改为 timeout
	void* si_AwaitCoroutine(Chan*, int64_t waiting);

	void* si_Coroutine_getData(Coroutine* co);
	void* si_GetCurrentCoroutineData();

	void si_Chan_Init(Chan*);
	/// 通过管道唤醒一个协程
	void si_Chan_BRACKETS(Chan*, void* data);
#ifdef __cplusplus
}
#endif
#endif
