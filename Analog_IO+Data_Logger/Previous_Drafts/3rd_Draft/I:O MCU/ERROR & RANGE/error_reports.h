#ifndef ERROR_REPORTS_H
#define ERROR_REPORTS_H

#define SYSTEM_REPORTS_ARRAY_SIZE 5

typedef enum {	ALL_MODULES_OK = 0,
				1_MODULE_HAS_ERROR,
				2_MODULES_HAVE_ERROR,
				3_MODULES_HAVE_ERROR,
				UNDEFINED_ERROR } SystemErrors;

typedef enum {	JOYSTICK_STATE = 0,
				JOYSTICK_ERROR_COUNTER,
				SYSTEM_STATE,
				RED,
				GREEN,
				BLUE } ReportArrayElements;
				
extern SystemErrors errorReportArray[SYSTEM_REPORTS_ARRAY_SIZE];

void printErrorReportArrayBuildError(void);
bool generateErrorReportArray(void);

#endif
