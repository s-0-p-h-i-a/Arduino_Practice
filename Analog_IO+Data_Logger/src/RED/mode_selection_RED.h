#include <stdint.h>

#ifndef SIGNAL_PROCESSING_RED_H
#define SIGNAL_PROCESSING_RED_H

typedef enum { NEUTRAL = 0, MODE1 = 1, MODE2 = 2 } JoystickModes;

RedLightModes computeRedLightMode(uint16_t input);

#endif
