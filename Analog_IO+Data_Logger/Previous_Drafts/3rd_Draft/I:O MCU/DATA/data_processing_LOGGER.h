#include <stdint.h>

#ifndef DATA_PROCESSING_LOGGER_H
#define DATA_PROCESSING_LOGGER_H

#define BITPACKING_ARRAY_SIZE 3
#define COLOURS_VALUES_ARRAY_SIZE 4

extern uint8_t potentiometerInput_DataPack[BITPACKING_ARRAY_SIZE];

extern uint8_t joystickInput_DataPack[BITPACKING_ARRAY_SIZE];

extern uint8_t waterLevelSensorInput_DataPack[BITPACKING_ARRAY_SIZE];

extern uint8_t colourModulesDataArray[COLOUR_MODULES_ARRAY_SIZE];

extern uint8_t systemReportsDataArray[SYSTEM_REPORTS_ARRAY_SIZE];

#endif
