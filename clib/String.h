#pragma once
#include <stdint.h>

struct Charset__sl
{
	uint16_t code;
};

#ifdef __cplusplus 
extern "C" {
#endif // 


void Init__Charset__sl(struct Charset__sl* ptr, uint16_t code);

struct String__sl {
	uint64_t length;
	int8_t alloc;
	wchar_t *data;
};

typedef struct String__sl String;

void Init__String__sl(String* str, char* data, uint64_t length, uint16_t encode);
void Finalize__String__sl(String* str);
// ±‡“Î∆˜ hack
String* Splice__String__sl(String* str, int64_t index, int64_t length);

uint64_t GET_size__String__sl(String*);
wchar_t at__String__sl(String* str, uint64_t index);
// char* si_String_Cast_i8_ptr(String*);

void sl_printInt(int value);
void print_X_PSU3Rya__sl(String* str);
void println_X_PSU3Rya__sl(String* str);

String* sl_String_PLUS_sl_String(String* str, String* right);
void sl_String_Init_I32(String* str, int32_t v);
void sl_String_Init_I64(String* str, int64_t v);
void sl_String_Init_M(String* str, float v);
void sl_String_Init_N(String* str, double v);
void sl_String_Init_sl_String(String* str, String* v);

#ifdef __cplusplus 
}
#endif // 