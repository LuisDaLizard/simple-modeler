#pragma once

#include <assert.h>

#ifndef __WIN32__
#define static_assert _Static_assert
#endif

#define TRUE    1
#define FALSE   0

#define NULL    0

typedef char                    i8;
typedef short                   i16;
typedef int                     i32;
typedef long long               i64;

typedef unsigned char           u8;
typedef unsigned short          u16;
typedef unsigned int            u32;
typedef unsigned long long      u64;

typedef float                   f32;
typedef double                  f64;

typedef char                    b8;
typedef int                     b32;

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

#define U8_MAX      0xFF
#define U16_MAX     0xFFFF
#define U32_MAX     0xFFFFFFFF
#define U64_MAX     0xFFFFFFFFFFFFFFFF