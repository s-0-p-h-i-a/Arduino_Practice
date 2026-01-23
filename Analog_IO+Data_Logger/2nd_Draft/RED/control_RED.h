#include <stdint.h>

#ifndef CONTROL_RED_H
#define CONTROL_RED_H

uint16_t getJoystickInput(void);
uint8_t getRedBrightness(void);
uint16_t getRedBlinkPause(void);

RangeErrorStatus getRedRangeHandlingStatus(void);

RedSystemStates controlRedLight(uint8_t redPin);

#endif
