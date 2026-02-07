PHOTORESISTOR + BUTTONS = RGB
10/10
-----------------------------------------
Goal:
Regulate RGB LED colour based on combined Serial, button, and photoresistor input.

Behaviour:
- Photoresistor: regulates blue light brightness (0–1023 → 0–255)
- Serial: defines brightness levels for red and green LEDs
- Button 1: toggles red LED (to Serial-defined brightness)
- Button 2: toggles green LED (to Serial-defined brightness)
- Blue brightness + red/green toggles run in a loop until new Serial input is given.

Structure:
- Get desired red and green brightness levels via Serial
- Enter loop: continuously update LED states based on buttons + photoresistor
- Modularised getLevel() handles Serial input with validation and scaling.

Notes:
- Simple integer range validation (0–100%) used to avoid unpredictable Serial input
- Blue level requires reversed analog input and 0–255 type conversion
- Serial timing and leftover bytes managed via manual delays and buffer clears
- Serial-based loop exit behaves differently than std::cin in C++
- Timing coordination between Serial I/O and loop execution was the main debugging focus.

Debug Log Summary:
- Fixed LED instability by rewiring (reduced interference/flicker)
- Discovered RGB LED does not support true brightness control (binary ON/OFF cutoff ~128)
- Timing issues caused Serial input lag and missed reads
- Adjusted delay placement (before/after getLevel) to synchronise Serial I/O and logic flow
- Learned to identify delay-related I/O timing interference and manual workaround points.

*/

// TO-DO: TEST WITH PWM PINS FOR LED (previously on digital pins)
/* 11/10

- Re wired so that the R, G, B legs are each connected to a PWM pin
- 1st test: photoresistor + blue leg only, isolate rest of code to test if LED allows for brightness regulation
- It works? The light flickers Re add rest of code and test again
- Not sure if serial input is working? Desired brightness values were stored as confirmed by serial input
- Next test: remove user input + red and green LED legs related code to test photoresistor input on plotter
- First time using the serial plotter, really cool!
- Test if brightness really is adjustable via removing/changing code
- No: same cutoff at 128 as before, even on PWM pin
- Idea: also regulate R and G legs via sensor input: define thresholds for R and G lights to go on
- Method: bool redON and greenON with ranges, include buffer between ranges to have clean signal
- Red light goes on when sensor input is lowest, green goes on at higher range
- It works!
- Still not sure if brightness not adjustable, as the LED is flickering in a different way now that it's on PWM pins
- Changed rgb wiring from common cathode (to GND) to common anode (to 5V) to test PWM functionality
- Added buttons functionality back to test R and G independently, R and G values set to below 128
- Doesn't work there or above 128: previous wiring was right
- Rewired RGB to GND, test again with values below 128: now it works!!
- Hard to create 'smooth' sensor onput: try smoothing out value with last value + current value average
- Consideration: at what point in the loop do i declare/assign value to currentSensorValue and lastSensorValue?
- Do declare them inside or outside the loop?
- Declare int currentSensorValue before loop + update right before avg calculation
- Declare+assign lastSensorValue at the start of loop 
- Print sensor input (analogread) and averageSensorValue to plotter: averageSensor curve is smoother
- Added button input variable to plotter
- 1-2 range too far from sensor input range: sensor+avg lines almost flat, buttons variation invisible
- Observation: plotter graph scale affects how input value graph looks
- Multiply buttons input by 300 to bring closer to sensor range
- Interesting to see how the curves react to input variation/fluctuation

- New test: plot adjusted redON and greenON values to see when sensor values go in and out of that range
- greenON is multiplied by 500,redON by 100 so they match the sensor value ranges where they would be on

- Idea: convert sensor input value to red and green leg output values
- To stay within valid values for rgb output: red = analogread/4, green = analogread/10
- Ajust sensor+avg value output range to match red and green level range: all %

- New test: define red and green output by matching sensor input to rgb scale and subtracting
-> discrete intervals for red and green
- The subtracted values have to be addeed back in the plotter variable definitions
- Added if check to catch case of level value < 0
- if check seems to completely disable red/green. maybe offset is too high?
- Removed if check, will explore this in later projects
- Hardware wise this is the same wiring as the main RGB project, without the buttons
- Left legacy if check and alternate non PWM boolean based range definitions
