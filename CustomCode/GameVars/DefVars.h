#include <stdbool.h>
#include <stdio.h>
#define ALIGN16 __attribute__((aligned(16)))
#define O_ALIGN(x) __attribute__((aligned(x)))

typedef	unsigned short	ushort;
typedef	unsigned int	uint;
typedef	unsigned long	ulong;