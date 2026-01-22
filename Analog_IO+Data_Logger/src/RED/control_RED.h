#include <stdint.h>

#ifndef CONTROL_RED_H
#define CONTROL_RED_H

#define NO_FAULTS_MESSAGE "Red system OK"
#define EXCESS_ERRORS_PAUSE_MESSAGE "Red system down: excess errors time out"
#define INVALID_INPUT_MESSAGE "Red system fault: invalid input"
#define UNDEFINED_ERROR_MESSAGE "Undefined error"

typedef enum { NO_FAULTS_CODE = 0, EXCESS_ERRORS_PAUSE_CODE = 1, INVALID_INPUT_CODE = 2 } RedSystemStates;

void controlRedLight(uint8_t redPin);

#endif
