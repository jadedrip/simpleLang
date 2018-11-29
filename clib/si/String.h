#pragma once
#include <stdint.h>

struct si_Charset
{
	uint16_t code;
};

void si_Charset_Init(struct si_Charset* ptr, uint64_t code)
{
	ptr->code = code;
}

struct si_String{
	uint64_t length;
	wchar_t *data;
	struct si_String* source;
	uint16_t encode;
};

void si_String_Init(struct si_String* str, char* data, uint64_t length, uint16_t encode);
void si_String_Finalize(struct si_String* str);
// ±‡“Î∆˜ hack
void si_String_Splice(struct si_String* str, uint64_t index, uint64_t length);

uint64_t si_String_GET_size(struct si_String*);
wchar_t si_String_at(struct si_String* str, uint64_t index);
char* si_String_Cast_i8_ptr(struct si_String*);