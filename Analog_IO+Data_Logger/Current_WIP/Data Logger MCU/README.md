#ANALOG I/O + DATA LOGGING PROJECT ==============================================================

This project consists of a system with 2 MCUS and I/O peripherals connected via UART:
	- A control MCU that creates output based on user input and periodically sends data to the data logger MCU
	- Data logger MCU receives control system snapshots and processes it for visual display

#Data logger MCU ==================================================================================

This MCU periodically receives 8-bit system data arrays, processes it into a local array and displays the data on the console and on an 8x8 LED matrix.

It receives I/O values and system status reports.

Analog input values from the I/O control MCU are packed into 3 element

#SYSTEM ==========================================================================================
##== INPUT ========================================================================================
- System data from I/O MCU

##== OUTPUT =======================================================================================
- Prints all transmitted data, formatted, onto console
- Writes data snapshots onto text file
- Matrix displays input and colour control value levels, clamped to [0,8]

##== STRUCTURE =====================================================================================
###==== Main program ================================================================================
- Reads input from serial, builds 'raw' input data array
- Processes data -> local data array
- Console output: prints data to console
- Matrix output: shows I/O data on LED matrix

###==== Data reception ============================================================================
- Analog uint16 values from input sources arrives bit-packed into 3 element uint8 array chunks:
	- input value / 255 (integer division)
	- input value % 255
	- flag: true if input value > 255
- Received data array:
	- 3x 3 element bit-packed data arrays: analog input values
	- 4x colour control values: brightness and red colour blink cycle
	- 2x joystick system status: error status code, error counter
	- 4x system data: whole system status code, 3x colour control status codes

###==== Data Output =================================================================================
- Console:
	- Local data array + reference files -> 2 display matrices: one for titles, one with data
- Matrix:
	- Shows I/O data: 3x input values, 1x RGB LED system control values, 3x individual LED leg control values)
	- I/O data clamped to [0, 8], variables are each assigned one column
	- Level 0: lights off, level 8: whole column on 

###==== Helper files ============================================================================
- Received data processing: builds local array
- Display data arrays: builds title + data arrays for console display
- Console display and error codes interfaces: libraries of strings to build titles array

!! NOT UPDATED !!
###==== Dependencies ================================================================================
- Structure:
	- data_reception_interface.cpp: receives data, builds received data array
	- data_processing_interface.cpp: processes received data array, builds local data array
	- system_snapshot.cpp: access interface for local data array
	- Console display path:
		- display_data_arrays.cpp builds 2 display arrays: char array for titles and error messages, uint array for data
			- Uses console display and error reports interfaces to build output array
		- console_display.cpp prints system snapshots to console
	- main .ino: calls readSystemSnapshot(), displayDataConsole(), displayDataMatrix()

!! NOT UPDATED !!
###==== Execution path example (console) ============================================================
- main .ino: main loop() calls readSystemSnapshot()
	-> system_snapshot.cpp: readSystemSnapshot() calls buildLocalDataArray()
		-> data_processing_interface.cpp: buildLocalDataArray() calls receiveDataArray()
			-> data_reception_interface.cpp: receiveDataArray() listens to serial port, receives input array if available
			-> receiveDataArray() exits
		-> buildLocalDataArray() calls getReceivedDataArray() and getReceivedSnapshotCounter() from data_reception_interface.cpp
		-> buildLocalDataArray() exits
	-> readSystemSnapshot() exits, back to main
		
- main calls displayDataConsole()
	-> console_display.cpp: displayDataConsole() calls buildConsoleDisplayArrays()
		-> display_data_arrays.cpp: buildConsoleDisplayArrays() builds array
		-> buildConsoleDisplayArrays() exits
	-> displayDataConsole() prints system data to console
	-> displayDataConsole() exits, back to main
