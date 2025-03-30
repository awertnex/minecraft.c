#ifndef DEFINES_H

#include <stdint.h>
#include <stdbool.h>

// ---- data types -------------------------------------------------------------
#define true 1
#define false 0

typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

typedef int8_t		i8;
typedef int16_t		i16;
typedef int32_t		i32;
typedef int64_t		i64;

typedef float		f32;
typedef double		f64;

typedef char		str;

typedef bool        b8;
typedef bool        b32;

#ifdef VECTOR2_TYPES
// ---- vector2u ---------------------------------------------------------------
typedef struct v2u8
{
	u8 x, y;
} v2u8;

typedef struct v2u16
{
	u16 x, y;
} v2u16;

typedef struct v2u32
{
	u32 x, y;
} v2u32;

typedef struct v2u64
{
	u64 x, y;
} v2u64;

// ---- vector2i ---------------------------------------------------------------
typedef struct v2i8
{
	i8 x, y;
} v2i8;

typedef struct v2i16
{
	i16 x, y;
} v2i16;

typedef struct v2i32
{
	i32 x, y;
} v2i32;

typedef struct v2i64
{
	i64 x, y;
} v2i64;

// ---- vector2f ---------------------------------------------------------------
typedef struct v2f32
{
	f32 x, y;
} v2f32;

typedef struct v2f64
{
	f64 x, y;
} v2f64;

#endif /* VECTOR2_TYPES */

#ifdef VECTOR3_TYPES
// ---- vector3u ---------------------------------------------------------------
typedef struct v3u8
{
	u8 x, y, z;
} v3u8;

typedef struct v3u16
{
	u16 x, y, z;
} v3u16;

typedef struct v3u32
{
	u32 x, y, z;
} v3u32;

typedef struct v3u64
{
	u64 x, y, z;
} v3u64;

// ---- vector3i ---------------------------------------------------------------
typedef struct v3i8
{
	i8 x, y, z;
} v3i8;

typedef struct v3i16
{
	i16 x, y, z;
} v3i16;

typedef struct v3i32
{
	i32 x, y, z;
} v3i32;

typedef struct v3i64
{
	i64 x, y, z;
} v3i64;

// ---- vector3f ---------------------------------------------------------------
typedef struct v3f32
{
	f32 x, y, z;
} v3f32;

typedef struct v3f64
{
	f64 x, y, z;
} v3f64;

#endif /* VECTOR3_TYPES */

#ifdef VECTOR4_TYPES
// ---- vector4u ---------------------------------------------------------------
typedef struct v4u8
{
	u8 x, y, z, w;
} v4u8;

typedef struct v4u16
{
	u16 x, y, z, w;
} v4u16;

typedef struct v4u32
{
	u32 x, y, z, w;
} v4u32;

typedef struct v4u64
{
	u64 x, y, z, w;
} v4u64;

// ---- vector4i ---------------------------------------------------------------
typedef struct v4i8
{
	i8 x, y, z, w;
} v4i8;

typedef struct v4i16
{
	i16 x, y, z, w;
} v4i16;

typedef struct v4i32
{
	i32 x, y, z, w;
} v4i32;

typedef struct v4i64
{
	i64 x, y, z, w;
} v4i64;

// ---- vector3f ---------------------------------------------------------------
typedef struct v4f32
{
	f32 x, y, z, w;
} v4f32;

typedef struct v4f64
{
	f64 x, y, z, w;
} v4f64;

#endif /* VECTOR4_TYPES */

#define DEFINES_H
#endif
