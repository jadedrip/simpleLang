#pragma once
#include <stdint.h>

struct si_String{
	uint64_t length;
	uint16_t encode;
	char *data;
	struct si_String* source;
	char alloc;
};

void si_String_init(struct si_String* str, uint16_t encode, char* data, size_t length, struct si_String* source /*= nullptr*/);
uint64_t si_String_GET_size(struct si_String*);
wchar_t si_String_at(struct si_String* str, uint64_t index);
char* si_String_Cast_i8_ptr(struct si_String*);