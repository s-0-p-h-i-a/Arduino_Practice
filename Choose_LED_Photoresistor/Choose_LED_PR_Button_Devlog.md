# Choose LED via Button & Photoresistor — Development Log

**Project Start:** 24/07  
**Goal:** Control two LEDs via either a push button or a photoresistor. Handle single-input and dual-input scenarios, including blinking when both inputs are active. Explore practical implementation of logic concepts.

---
## Initial Concept

- Combine recently learned boolean arithmetic with Arduino I/O.  
- Use flag variables to track which input should turn on which LED.  
- Consider edge cases: what happens if both inputs are active, or no input is present?  
- Aim for clean loop logic: reset LEDs at the start or end of each loop to avoid stuck LEDs.  

---
## Design Decisions

1. **LED Control Strategy**  
   - Green LED → photoresistor  
   - Blue LED → push button  
   - Both inputs → blink both LEDs  

2. **Input Handling**  
   - AnalogRead for photoresistor, digitalRead for button  
   - Initial approach: calculate all input combinations with flag variables: photoresistorONLY, buttonONLY, bothInputs  

3. **Reset Checkpoints**  
   - Start of each loop: turn off LEDs if no input  
   - Keeps loop deterministic and prevents LED “sticking”  

4. **Boolean Flags**  
   - Initially used int variables to represent booleans (0 or 1)  
   - Realized Arduino C++ supports boolean type; leaving int for learning trace  

5. **Blink Logic**  
   - while loop used when both inputs are active  
   - Reads inputs repeatedly to ensure real-time responsiveness  
   - Delay durations: 200 ms on, 100 ms off for visible blinking  

---
## Implementation Challenges

- Boolean Variables: Concerned that flag values wouldn’t update properly each loop → confirmed reassignment at each loop iteration works.  
- LED Reset: Needed to explicitly turn off LEDs at start of loop to prevent carryover from previous loop.  
- Simultaneous Inputs: Blink behaviour required while loop, but had to ensure inputs were read inside the loop to avoid infinite blinking.  
- Analog Threshold: Chose <= 450 experimentally for low-light detection.  

---
## Debugging Notes

- Confirmed button wiring and photoresistor wiring were correct.  
- Verified LED pins set to OUTPUT and input pins set to INPUT.  
- Tested each input individually first, then combined.  
- Observed expected behaviour:  
  - Photoresistor alone → green LED ON  
  - Button alone → blue LED ON  
  - Both → LEDs blink simultaneously  

- Iterated several times to optimize readability and logical flow of if / else if blocks.  

---
## Learning Highlights

- Boolean arithmetic can simplify multi-condition logic in embedded systems.  
- Always reset outputs at start of loop to avoid unintended states.  
- Careful sequencing of conditional statements prevents input conflicts.  
- Combining digital and analog inputs requires careful calibration and testing.  
- Flag variables (boolean or int) can act as checkpoints for decision logic.  

---
## Next Steps / Future Project Ideas

- Refactor LED handling and reset logic into functions for better modularity.  
- Explore boolean type fully instead of int “booleans”.  
- Experiment with arrays for multiple LEDs and inputs.  
- Consider adding debounce for button input.  
- Record demo video to show behaviour under different lighting and button presses.  

---
This dev log was generated from code, in-code comments and raw dev notes, formatted and structured with AI assistance for clarity.  
For a full explanation of the workflow and AI use, see the README.