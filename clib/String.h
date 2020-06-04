#pragma once
#include <stdint.h>

struct si_Charset
{
	uint16_t code;
};

#ifdef __cplusplus 
extern "C" {
#endif // 


void si_Charset_Init(struct si_Charset* ptr, uint16_t code);

struct si_String {
	uint64_t length;
	int8_t alloc;
	wchar_t *data;
};

typedef struct si_String String;

void si_String_Init(String* str, char* data, uint64_t length, uint16_t encode);
void si_String_Finalize(String* str);
// ±‡“Î∆˜ hack
String* si_String_Splice(String* str, int64_t index, int64_t length);

uint64_t si_String_GET_size(String*);
wchar_t si_String_at(String* str, uint64_t index);
// char* si_String_Cast_i8_ptr(String*);

void si_printInt(int value);
void si_print_si_String(String* str);
void si_println(String* str);

String* si_String_PLUS_si_String(String* str, String* right);
void si_String_Init_I32(String* str, int32_t v);
void si_String_Init_I64(String* str, int64_t v);
void si_String_Init_M(String* str, float v);
void si_String_Init_N(String* str, double v);
void si_String_Init_si_String(String* str, String* v);

#ifdef __cplusplus 
}
#endif // 