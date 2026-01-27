#include <stdint.h>

#ifndef RANGE_HANDLING_H
#define RANGE_HANDLING_H

typedef enum { 	NO_RANGEHANDLING_ERRORS 		= 0,	
				ANALOGMAX_EXCEEDED 				= 1,
				RGBMAX_EXCEEDED 				= 2,
				ANALOG_AND_RGBMAX_EXCEEDED		= 3,
				UNDEFINED_RANGEHANDLING_ERROR 	= 4 } RangeErrorStatus;

uint8_t clampInputToRGBRange(uint16_t sensorInput);

#endif
