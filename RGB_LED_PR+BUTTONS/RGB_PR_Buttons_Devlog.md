# Dev Log: RGB LED + Photoresistor + Buttons

## Project Goal

- Create an interactive system to control an RGB LED using:
  - **Photoresistor** input to modulate blue LED brightness.
  - **Buttons** to toggle red and green LEDs.
  - **Serial input** to define red and green brightness levels dynamically.
- Focus was on **embedded programming practice**, hardware interaction, and debugging — the final functionality was secondary to the learning process.

---
## Practiced Topics

1. **Embedded I/O**
   - Digital input reading (`digitalRead`) and output writing (`analogWrite` / PWM).
   - Analog sensor reading (`analogRead`) and value mapping for LED brightness.

2. **Serial Communication**
   - Reading numeric input from Serial (`Serial.parseInt()`).
   - Handling leftover Serial bytes to prevent unexpected behaviour.
   - Synchronising Serial I/O with program flow using `delay()` and manual byte cleanup.

3. **Timing & Delays**
   - Understanding effect of `delay()` on loop execution.
   - Observing how timing mismatches between input, processing, and output affect behaviour.

4. **Debugging Embedded Hardware**
   - Diagnosing flicker and signal instability caused by wiring layout and LED behaviour.
   - Learning hardware limitations (RGB LED binary cutoff at ~128).

5. **Program Structure**
   - Modularised input reading via `getLevel()` function.
   - Conditional output control using ternary expressions.
   - Transitioning between intended multi-feature design and simplified working version.

---
## Experimentation & Debugging Journey

### 1. Initial Implementation

- **Intended Features:**
  - Serial input for red and green brightness (0–100%).
  - Photoresistor regulates blue LED dynamically (PWM).
  - Buttons toggle red and green LEDs in real-time while allowing continuous blue adjustment.

- **Challenges Observed:**
  - Serial input was unreliable: sometimes skipped prompts or values read as `0`.
  - PWM on RGB LED legs ineffective; hardware only supports full ON/OFF states.
  - Flickering caused by wiring layout and grounding issues.
  - Timing mismatches between Serial reads, loop iteration, and analog readings.

- **Debugging Actions:**
  - Rewired LED and resistors to reduce flicker and interference.
  - Added delays before and after `getLevel()` to allow Serial input to stabilise.
  - Printed Serial values to track what was being read.
  - Experimented with progressive feature removal to isolate issues.

### 2. Intermediate Insights
- LED hardware limitation made dynamic brightness control infeasible.
- Serial input timing can interfere with real-time button/analog input loop.
- Incremental testing (removing features, adding debug prints) is more effective than guessing.

### 3. Final Working Version
- Simplified design to respect hardware constraints:
	- Buttons now toggle red and green LEDs directly (ON/OFF).
	- Photoresistor triggers blue LED when light is below threshold.
- Achieved stable, predictable behaviour.
- Key lessons: timing, hardware limits, input/output coordination.

---
## Program Structure Overview

### Intended Version (with Serial brightness input)
```cpp
int getLevel(String colour) {
    // Reads and validates brightness from Serial (0–100%), converts to 0–255
}

void loop() {
	// SERIAL INPUT READ
	delay(3000);
	
	int redLevel = getLevel("red");
	delay(3000);
	
	int greenLevel = getLevel("green");
	delay(3000);
	
	// PAUSE REST OF PROGRAM AND STAY IN LOOP WITH STATIC RED&GREEN BRIGHTNESS
	// UNTIL SERIAL INPUT TO EXIT & START OVER
	bool continueLoop(true);
	
	do {
		bool button1ON = digitalRead(button1Pin);
		bool button2ON = digitalRead(button2Pin);
		int blueLevel = 255 * round(1.0 - (analogRead(photoresistorPin)/1023.0));
		
		analogWrite(redPin, button1ON ? redLevel : 0);
		analogWrite(greenPin, button2ON ? greenLevel : 0);
		analogWrite(bluePin, blueLevel);
		
		continueLoop = Serial.available() == 0;
		
		delay(10);
		
	} while (continueLoop);
}
```

#### Key Features Practiced:

- Serial input parsing, validation, and conversion

- PWM output mapping

- Loop with dynamic real-time behavior

- Conditional output via ternary operators

---
### Final Working Version (binary LED behavior)

```cpp
void loop() {
    bool button1ON = digitalRead(button1Pin);
    bool button2ON = digitalRead(button2Pin);
    bool photoresistorActive = analogRead(photoresistorPin) < 450;

    analogWrite(redPin,   button1ON ? ON : OFF);
    analogWrite(greenPin, button2ON ? ON : OFF);
    analogWrite(bluePin,  photoresistorActive ? ON : OFF);
}
```

#### Simplifications Made:

- Removed Serial brightness input (`getLevel()` function).

- Blue LED now binary: ON/OFF based on photoresistor threshold.

- Loop focuses on reliable digital + analog input control.

---
## Takeaways

1. **Embedded programming is timing-sensitive**

    - Loop iteration, sensor reads, and output writes interact differently than in standard console programming.

2. **Hardware defines software limits**

    - RGB LED could not support intended brightness control, highlighting importance of component capabilities.

3. **Incremental debugging is essential**

    - Testing piece by piece, using debug prints and rewiring, helped isolate issues.

4. **Code modularity aids experimentation**

    - `getLevel()` and ternary output expressions allowed easy removal/refactoring without breaking structure.

5. **Learning is the goal**
    
    - Even though the final behaviour is simpler than intended, the process taught critical embedded systems skills: I/O handling, debugging, timing, and hardware/software integration.

---
## Next Steps

- Use PWM-capable LEDs to restore analog brightness control.

- Implement non-blocking Serial input for real-time user interaction.

- Expand with multiple sensors or additional outputs for more complex embedded exercises.

---
## Documentation Workflow & AI Assistance

All documentation in this project (README, dev logs, and code comments) is based on original notes written manually during development.

To improve clarity and consistency, AI tools are used to:

- Draft new READMEs from raw notes
- Generate dev logs tracing reasoning and changes
- Condense raw notes into concise in-code comment blocks

**All generated documentation is manually reviewed and edited.** 