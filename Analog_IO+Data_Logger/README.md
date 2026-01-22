ANALOG I/O + DATA LOGGING PROJECT ==============================================================

This system combines analog input from a water level sensor, a joystick and a potentiometer to control an RGB LED.
Each input source controls the brightness of one RGB LED leg. The joystick can either control the red colour brightness or make it toggle on/off.

It uses input and error handling modules to ensure proper execution.

I/O data is collected and processed for serial monitor display and transmission to data logger MCU via UART.
Serial monitor visualisation is used to support hw/sw integration and debugging.
Data logger takes regular system snapshots, displays them in terminal, and saves them in log file.

GOALS ==========================================================================================
The goal of this project is to create a comprehensive sandbox to practice various SWE concepts + start learning hardware communications:
	- System structure design:
		- Architecture							- Modularisation
		- Dependencies							- Data flow
		- Encapsulation							- Execution paths
	- Safety integration:
		- Preventing undefined behaviour and invalid inputs
		- Implementing error handling systems (error codes, error messages)
		- Defining response behaviour when errors occur
	- Documentation:
		- Writing and processing structured notes during development, instead of taking raw notes and processing later
		- Notes structure:
			- Progressively build a README: describe system as it is developed for more accurate explanations
			- Progressively build a dev log: track progress and explain build process
		- Mapping out program structure, behaviour and dependencies in writing before development
		- In-code comments
		- Functions index
	- Communications:
		- First steps in learning to implement systems communication via UART
		- Connecting I/O system with data logger MCU to display system snapshots in terminal
		
SYSTEM ==========================================================================================
== INPUT ========================================================================================
- Joystick (analog 0-1023)
- Water level sensor (analog 0-1023)
- Potentiometer (analog 0-1023) 

== OUTPUT =======================================================================================
- RGB LED (PWM 0-255)

Red = Joystick, Green =  Water level sensor, Blue = Potentiometer

== INPUT RESPONSE ================================================================================
==== Joystick ====================================================================================
- Neutral (511 ± hyst) = red OFF
- Up (±511 - 1023) -> red goes from 0 to 255
- Down (±511 - 0) -> red blinks progressively faster, delay 1000ms to 20 ms

==== Water level sensor ==========================================================================
- 0 = green 0, 1023 = green 255

==== Potentiometer ===============================================================================
- 0 = blue 255, 1023 = blue 0

== STRUCTURE =====================================================================================
==== Main program ================================================================================
- Hardware input interfaces read data from analog input sources
- Red light/joystick has intermediary mode selection module
- Control interfaces for each colour take read data, process it and use for individual RGB leg actuation
- Main RGB module calls individual colour control functions
- Main calls RGB control function

==== Safety and error handling ===================================================================
- Range handling module prevents values outside of valid ranges
- Error handling module with error codes, error messages and error response behaviour functions

==== Helper libraries ============================================================================
- Main raw data handling interface
- Data processing for arduino IDE serial plotter display
- Data processing for data logger MCU

==== Dependencies ================================================================================
- Hardware:
	- Input reading only modules, do not include anything
- Red light:
	- Mode selection module:
		- Includes range handling module
		- Enum for input modes (used by control interface)
	- Control interface module:
		- Includes: joystick input reading, mode selection, range handling, and error handling modules
		- Uses input modes enum from mode selection
- Other lights:
	- Control interface modules:
		- Include: associated hardware input modules, range handling module
- Central RGB control:
	- Includes individual colour control modules, calls their respective actuation functions
	- Macros for pin numbers
- Main:
	- Includes RGB control module, calls main RGB control function, uses pin number macros from RGB module for setup
- Error handling module:
	- Includes nothing
- Visualisation:
	- Raw data interface: includes hardware and colour control modules
	- Data processing (plotter): includes raw data interface
	- Data processing (logger): includes raw data interface
	- Plotter module: includes data processing interface (plotter)
	- Logger module: includes data processing interface (logger)
	
== BEHAVIOUR ======================================================================================
==== Intended execution path ======================================================================
A loop cycle starts
(main.ino)	-> main calls RGB control function in void loop
(rgb_led.cpp)	-> central RGB control function calls control function from a colour
(control_COLOUR.cpp)	-> a colour control function calls hardware read function*
(hardware_input.cpp)		-> read function takes hardware input, sends to colour control function, finishes execution
(control_COLOUR.cpp)	-> colour control function uses hardware input data to control colour pin, finishes execution
(rgb_led.cpp)	-> RGB function calls the two other colour control functions finishes execution
(main.ino)	-> void loop finishes execution

*red control function calls both hardware input function and signal processing function

==== Safety =======================================================================================
- Range handling header:
	- limitToAnalogMax for hardware input values, max 1023
	- limitToRGBMAX for translated input values, max 255
	- clampToRGBRange to translate input values from analog range to RGB range
- Enums/states for error handling
- Red light control module as sandbox to brainstorm error handling

==== Visualisation & data logging =================================================================
- Raw data interface takes I/O values
- Data processing (plotter): shifts/amplifies data for clear plotter visuals
- Data processing (logger): provides data for transmission via UART

== REQUIREMENTS ===================================================================================
==== Goal =========================================================================================
- Limit data and function execution scopes+lifecycles to only when relevant/necessary
- Direct path from sensor/controller input data to LED control output
- RGB legs + associated input hardware are handled one by one
- Clear and readable semantics

==== Intended system type =========================================================================
- The design philosophy/choices are intended for:
	- Performance-oriented control firmware
	- Portability for data logger integration
- In practice:
	- As little concurrent processes as possible
	- System response as immediate as possible
	- Taking into account that data will be used by a data logger controller to take system snapshots
	- Integrate error + undefined behaviour prevention/handling
	
====================================================================================================

PROCESS ============================================================================================
== Planning ========================================================================================
- Define:
	- Desired I/O behaviour
	- Program structure
	- Dependencies
- Map out intended execution path

== Initial development =============================================================================
- Build base: input, colour control and LED control modules, main .ino file
- Integrate input handling/safety measures
- Write data interface modules
- Write data logger MCU code

== SW Review =======================================================================================
- Compile checks:
	- Start with only one input + colour control combination, LED, and safety modules (green or blue for simplicity)
	- Add the 2 other input + colour control systems
	- Add data interfaces
	- Check data logger MCU

== HW/SW integration ===============================================================================
- Using plotter display:
	- Start with only one input + colour control
	- Add the 2 other input + colour combos
	- Exclude data logger interface
- Once plotter display is verified & validated, move on to communication with data logger:
	- Level 1: data interface sends one constant variable to logger, test for different values
	- Level 2: integrate one hardware input source, then its associated colour control values
	- Level 3: integrate rest of system
	
====================================================================================================
DEVELOPMENT NOTES ==================================================================================
22/01
- First draft code written for I/O system, basic scaffolding for data interfaces
- First README version done
- Functions index: complete for all first draft modules, no data interfaces yet
- Idea: implement flag for when a value has to be capped to fit valid range, as part of error handling system

====================================================================================================

TO-DO:
- Finish writing data processing + display modules for plotter
- Write processing module for data logger
- Update functions index, README and dev notes
- Compile checks/reviews
- HW/SW integration: one MCU + serial plotter display
- Write data logger MCU code
- Compile check data logger MCU code
- Communication integration
- Make structure/execution diagrams
- Make state diagrams:
	- FSMs: colour control, error handling
	- Block+register: overall logic, input handling
- Make schematics
- Create demo content
- Consolidate documentation + demos
- Commit + push
