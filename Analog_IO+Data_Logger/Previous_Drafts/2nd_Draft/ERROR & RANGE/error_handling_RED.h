#ifndef ERROR_HANDLING_RED_H
#define ERROR_HANDLING_RED_H

typedef enum { 	NO_FAULTS_CODE = 0,
				EXCESS_ERRORS_PAUSE_CODE = 1,
				INVALID_INPUT_CODE = 2 } RedSystemStates;

void handleJoystickInputError(void);
bool checkIfExcessErrorsBufferElapsed(void);
void resetErrorTracking(void);

#endif
