#include <stdint.h>

#ifndef DATA_PROCESSING_LOGGER_H
#define DATA_PROCESSING_LOGGER_H

#define BITPACKING_ARRAY_SIZE 3
#define COLOUR_MODULES_ARRAY_SIZE 4

uint8_t potentiometerInput_DataPack[BITPACKING_ARRAY_SIZE];

uint8_t joystickInput_DataPack[BITPACKING_ARRAY_SIZE];

uint8_t waterLevelSensorInput_DataPack[BITPACKING_ARRAY_SIZE];

uint8_t colourModulesDataArray[COLOUR_MODULES_ARRAY_SIZE];

uint8_t redBrightnessLevel_LOGGER;
uint8_t redPauseTime_LOGGER;
uint8_t greenBrightnessLevel_LOGGER;
uint8_t blueBrightnessLevel_LOGGER; 

#endif
