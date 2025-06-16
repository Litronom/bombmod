#ifndef CUSTOMSTRUCT_H_
#define CUSTOMSTRUCT_H_

#include "../MainInclude.h"

#define WRAP_MIN_MAX(value, min, max) ((((max) - (min) + 1) <= 0) ? 0 : ((min) + (((value) - (min) + ((max) - (min) + 1)) % ((max) - (min) + 1))))

typedef struct ControllerEX{

	short		AnalogX;
	short		AnalogY;

	short		ButtonHeld;
	ushort		ButtonPressed;
	ushort		ButtonReleased;

	short		padding;

} ControllerEX;

#endif