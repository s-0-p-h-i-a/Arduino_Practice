#ifndef ERROR_REPORTS_H
#define ERROR_REPORTS_H

typedef enum {	ALL_MODULES_OK = 0,
				1_MODULE_HAS_ERROR = 1,
				2_MODULES_HAVE_ERROR = 2,
				3_MODULES_HAVE_ERROR = 3 } SystemErrors;
				
SystemErrors errorReportMatrix[COLOUR_MODULES_QUANTITY];

SystemErrors checkRangeHandlingThisLoop(void);

#endif
