/**
ANALOG I/O + DATA LOGGING PROJECT ==============================================================

This project consists of a system with 2 MCUS and I/O peripherals connected via UART:
	- A control MCU that creates output based on user input and periodically sends data to the data logger MCU
	- Data logger MCU receives control system snapshots and processes it for visual display

Data logger MCU ==================================================================================

This MCU periodically receives 8-bit system data arrays, processes it into a local array and displays the data on the console and on an 8x8 LED matrix.

It receives I/O values and system status reports.

Analog input values from the I/O control MCU are packed into 3 element

See README for more info.

====================================================================================================
DEVELOPMENT NOTES ==================================================================================

24/01
- Data receive, data unpack, system snapshot build, data display console, data display matrix modules started

25/01
- Finished 1st draft of data logger MCU code .cpp files
- Structure:
	- data_reception_interface.cpp: receives data, builds received data array
	- data_processing_interface.cpp: processes received data array, builds local data array
	- system_snapshot.cpp: builds system snapshot from local data array
	- data_processing_*.cpp: displays system snapshot on console, displays analog input + colours data on LED matrix
	- main .ino: calls readSystemSnapshot(), displayDataConsole(), displayDataMatrix()
	
- Execution path example (console):
	- main .ino: main loop() calls readSystemSnapshot() from system_snapshot.cpp
		-> system_snapshot.cpp: readSystemSnapshot() calls buildLocalArray() from data_processing_interface.cpp
			-> data_processing_interface.cpp: buildLocalArray() calls receiveDataArray() from data_reception_interface.cpp
				-> data_reception_interface.cpp: receiveDataArray() reads serial input, builds receivedDataArray
				-> data_reception_interface.cpp: receiveDataArray() finishes execution
			-> data_processing_interface.cpp: buildLocalArray() calls getReceivedDataArray() and getReceivedSnapshotCounter()
				-> data_reception_interface.cpp: getReceivedDataArray() and getReceivedSnapshotCounter() return the values
				-> data_reception_interface.cpp: getReceivedDataArray() and getReceivedSnapshotCounter() finish execution
			-> data_processing_interface.cpp: buildLocalArray() builds localDataArray, finishes execution
		-> system_snapshot.cpp: readSystemSnapshot() finishes execution
	- main .ino: main loop calls displayDataConsole() from data_display_CONSOLE.cpp
		-> data_display_CONSOLE.cpp: displayDataConsole() calls getSystemSnapshotData() from system_snapshot.cpp
			-> system_snapshot.cpp: getSystemSnapshotData() calls getLocalArray() from data_processing_interface.cpp
				-> data_processing_interface.cpp: returns localDataArray element, finishes execution
			-> system_snapshot.cpp: getSystemSnapshotData() finishes execution	
		-> data_display_CONSOLE.cpp: displayDataConsole() finishes execution
	- back to main .ino, calls displayDataMatrix, same path

26/01
- Wrote data display and error message parsing + display modules
	
27/01
- Data processing interface previously generated 3 separate array for the bit packed data from each input (pot, joystick, water sensor)
- Now it builds one [9] array and unpack bits func generates uint16 value out of any given 3 elements
- In buildLocalDataArray: j = i * BITPACKED_UNIT_SIZE; indices used inside for loop.
	- i = amount of unpacked data elements to build out of received data array containing data packed in BITPACKED_UNIT_SIZE elements
	- BITPACKED_UNIT_SIZE = amount of elements inside each data packed to be unpacked into one element
- Finished adding header guards
- Compilation: minor include/dependency and syntax errors only, no changes made or required
- COMPILES
- Finished and compiled data logger code
- Started writing data logger mcu documentation

====================================================================================================
TO-DO:
I/O MCU:
- Update functions index, README and dev notes
- Compile checks/reviews
- HW/SW integration: one MCU + serial plotter display
- Update functions index
	
DATA LOGGER MCU:
- Start documentation
- Compile check DONE
- Functions index

FULL SYSTEM:
- Communication integration
- Make structure/execution diagrams
- Make state diagrams:
	- FSMs: colour control, error handling
	- Block+register: overall logic, input handling
- Make schematics
- Create demo content
- Consolidate documentation + demos
- Commit + push

	
 arduino-cli compile --fqbn arduino:avr:uno data_logger.ino

*/

#include "console_display.h"
#include "matrix_display.h"
#include "system_snapshot.h"
#include <arduino.h>

void setup(void) {
	
	initialiseMatrix();
	Serial.begin(9600);
}

void loop(void) {
	
	readSystemSnapshot();

	displayDataConsole();
	displayDataMatrix();
}
