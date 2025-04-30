#pragma once

#include <assert.h>

#ifndef WIN32
#define static_assert   _Static_assert
#define NULL    ((void*)0)
#endif

#define TRUE    1
#define FALSE   0

typedef char                        i8;
typedef short                       i16;
typedef int                         i32;
typedef long long                   i64;

typedef unsigned char               u8;
typedef unsigned short              u16;
typedef unsigned int                u32;
typedef unsigned long long          u64;

typedef float                       f32;
typedef double                      f64;

typedef char                        b8;
typedef int                         b32;

typedef struct { u8 r, g, b, a; }   rgba8;

static_assert(sizeof(i8) == 1, "i8 must be 1 byte");
static_assert(sizeof(i16) == 2, "i16 must be 2 bytes");
static_assert(sizeof(i32) == 4, "i32 must be 4 bytes");
static_assert(sizeof(i64) == 8, "i64 must be 8 bytes");

static_assert(sizeof(u8) == 1, "u8 must be 1 byte");
static_assert(sizeof(u16) == 2, "u16 must be 2 bytes");
static_assert(sizeof(u32) == 4, "u32 must be 4 bytes");
static_assert(sizeof(u64) == 8, "u64 must be 8 bytes");

static_assert(sizeof(f32) == 4, "f32 must be 4 bytes");
static_assert(sizeof(f64) == 8, "f64 must be 8 bytes");

static_assert(sizeof(b8) == 1, "b8 must be 1 byte");
static_assert(sizeof(b32) == 4, "b32 must be 4 bytes");

static_assert(sizeof(rgba8) == 4, "rgba8 must be 4 bytes");

#define HEX_TO_RGBA8(hex) { hex & 0xFF, (hex >> 8) & 0xFF, (hex >> 16) & 0xFF, (hex >> 24) & 0xFF }
#define RGBA8_TO_HEX(rgba8) ( *((u32*)&rgba8) )

#define U8_MAX      0xFF
#define U16_MAX     0xFFFF
#define U32_MAX     0xFFFFFFFF
#define U64_MAX     0xFFFFFFFFFFFFFFFF

#define MESSAGE_BUFFER_MAX 512

void
smAssert(b32 condition);

void
smAssertF(b32 condition, const char *format, ...);