#include <stdint.h>

#ifndef DISPLAY_DATA_ARRAYS_H
#define DISPLAY_DATA_ARRAYS_H

static const uint8_t DISPLAY_ARRAY_SIZE = 17;
static const uint8_t ERROR_MESSAGES_ARRAY_SIZE = 6;

extern bool displayArrayBuilt;

extern char consoleDisplayArray_Titles[DISPLAY_ARRAY_SIZE];
extern uint16_t consoleDisplayArray_Data[DISPLAY_ARRAY_SIZE];
extern char errorMessagesArray[ERROR_MESSAGES_ARRAY_SIZE];

extern bool buildConsoleDisplayArrays(void);

#endif
