#include "../MainInclude.h"

#define ALIGN16 __attribute__((aligned(16)))
#define O_ALIGN(x) __attribute__((aligned(x)))

typedef	unsigned short	ushort;
typedef	unsigned int	uint;
typedef	unsigned long	ulong;

union {
    float f;
    uint32_t i;
} float2hex;