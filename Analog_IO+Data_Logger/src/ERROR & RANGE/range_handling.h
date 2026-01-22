#include <stdint.h>

#ifndef RANGE_HANDLING_H
#define RANGE_HANDLING_H

uint16_t limitToAnalogMax(uint16_t analogInput);
uint8_t limitToRGBMax(uint16_t inputValue);
uint8_t clampInputToRGBRange(uint16_t sensorInput);

#endif
