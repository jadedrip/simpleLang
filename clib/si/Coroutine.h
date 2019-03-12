#pragma once
#include <stdint.h>
#include <setjmp.h>

struct si_Coroutine {
	jmp_buf buf;	// Ìø×ªµØÖ·
	int64_t value;	// Öµ
};