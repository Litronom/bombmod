#include "../MainInclude.h"

#ifndef DEFVARS_H_
#define DEFVARS_H_

#define ALIGN16 __attribute__((aligned(16)))
#define O_ALIGN(x) __attribute__((aligned(x)))

typedef	unsigned short	ushort;
typedef	unsigned int	uint;
typedef	unsigned long	ulong;

#define SET_FLAG(n, f) ((n) |= (f)) 
#define CLR_FLAG(n, f) ((n) &= ~(f)) 
#define TGL_FLAG(n, f) ((n) ^= (f)) 
#define CHK_FLAG(n, f) ((n) & (f))

typedef union {
    float f;
    uint i;
}
hex2float;

#endif