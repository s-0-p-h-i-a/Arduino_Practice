# PHOTORESISTOR + BUTTONS = RGB

# Goal: regulate RGB colour based on combined serial + buttons + photoresistor input

# Behaviour:

- PR input alone regulates blue light brightness (PR input ranges from 0 to 1023 -> convert x*(255/1023))

- Serial input: choose brightness level for red and green lights

- Button 1 input: turn on red light (to serial defined brightness)

- Button 2 input: turn on green light (to serial defined brightness)

- User can vary blue light brightness + red and green lights on/off in a loop, exit to enter new red and green brightness levels

---
# Structure:

- Get desired red + green light brightness levels

- getLevel function to modularise desired red/green light level reading

- Stay inside a while loop that allows user to adjust blue light brightness and whether the red and green lights are on

---
# Notes:

- Choosing to limit myself to simple int value range input validation to avoid unpredictable behaviour, case of user entering other types is disregarded for now to focus on behaviour logic implementation. Implicit type conversion + range check makes sure the program only moves forward with usable values

- blueLevel value assignment: need to reverse analog input value + convert to 0-255 range required type conversion consideration

- Need to take serial read leftover bytes/delay into account: manually discarding bytes, adding delay to main behaviour while loop

- Use of serial response to trigger while loop exit: different behaviour from std::cin

- For future reference: look up how to keep program paused when expecting serial user input

- Timing coordination issues with serial i/o and program running

---
# LOG:

- Wired, tested: program not behaving as intended

- Noticed RGB LED instability -> rewired so corresponding resistors and cables are further apart, fixed flicker + response to me touching laptop casing

- Serial issues: program would ask for red level then immediately green level then stop waiting for serial input to exit while loop. Fixed by adding 5s delay in getLevel

- Program still not behaving as intended: no red or green

- Progressive removing/changing parts of code + testing led to conclusion:
	this RGB LED does not support brightness levels, each leg is either ON or OFF, cutoff at 128

- Re-added serial input + function + etc + some tweaks: looks like maybe partial brightness is supported? Or wiring issue, but low blue light is constant, no flickers

- getLevel not working: serial looks ok but nothing happens when buttons pressed

- Add serial output to track read values

- getLevel delay was too long, causing interference

- Moved delay outside of getLevel as it was causing i/o and data flow issues (eg delay before printing and returning value)

- Delays at beginning of loop + after each getLevel call to make program wait for i/o flow to catch up

- Added short delays in getLevel before+after input: adjusting these delays helps understand where/how much lag is happening

- Manageable behaviour reached with 1000ms delay before+after input

- Timing issues led to serial reads nothing -> level value saved as 0

- Will look up the proper way to wait for user input, for now it is interesting to add/remove delays to find at what points the i/o timing and code execution timing discrepancies are causing faulty behaviour