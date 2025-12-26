#include "../MainInclude.h"

#ifndef DEFVARS_H_
#define DEFVARS_H_

#define INVALID_PTR ((void*)-1)

#define ALIGN16 __attribute__((aligned(16)))
#define O_ALIGN(x) __attribute__((aligned(x)))

typedef	unsigned short	ushort;
typedef	unsigned int	uint;
typedef	unsigned long	ulong;

#define SET_FLAG(n, f) ((n) |= (f)) 
#define CLR_FLAG(n, f) ((n) &= ~(f)) 
#define TGL_FLAG(n, f) ((n) ^= (f)) 
#define CHK_FLAG(n, f) ((n) & (f))

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof((array)[0]))

#define min(value, min) ((value) = ((value) < (min) ? (min) : (value)))
#define max(value, max) ((value) = ((value) > (max) ? (max) : (value)))
#define clamping(value, min, max) ((value) < (min) ? (min) : ((value) > (max) ? (max) : (value)))
#define wrap_min_max(value, min, max) ((min) + (((value) - (min) + ((max) - (min) + 1)) % ((max) - (min) + 1)))
#define abs(a) ((a) < 0 ? -(a) : (a))
#define swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))
#define copy(dest, src) dest = src
#define round_up(x, y) (((x) + (y) - 1) / (y) * (y))
#define round_down(x, y) ((x) / (y) * (y))
#define sign(x) ((x) < 0 ? -1 : ((x) > 0 ? 1 : 0))
//#define rndfloat ((float)(rand_limit(max)) / max);

typedef union {
    float f;
    uint i;
}
hex2float;

#endif