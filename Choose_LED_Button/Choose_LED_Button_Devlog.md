# 📓 Dev Log — Choose LED via Button Input

## Date

06/07 → 23/07

## Concept

Create a simple interactive circuit where the user can choose which LED to light up by pressing one of two buttons.

- 2 buttons as **input**
    
- 2 LEDs (green and blue) as **output**
    

Goal: when a button is pressed, its corresponding LED lights up. When the button is released, the LED turns off.

---
## Process & Thought Flow

### Initial Plan

- Started by refactoring the earlier “Choose LED via Serial” sketch into a button-controlled version.
    
- Questions I wanted to resolve:
    
    - Should I use `while` loops or simple `if` branches?
    - Do I need two independent logic blocks for each button?
    - How will the program behave if both buttons are pressed?

### First Implementation

- Went with two `if` branches (one per button).
- Expected behaviour: button press → LED on, release → LED off.
- No delay or latching; LEDs should only reflect real-time button state.

### Debugging Round 1

- LEDs weren’t responding as expected.
- Tried removing the “LEDs off” reset instructions, then tried `while` loops. Still failed.
- Added serial output checks to confirm button reads. No success: microcontroller wasn’t detecting button presses.
- Realised I had mistakenly set both **LED pins** as `INPUT` instead of `OUTPUT`. Fixed that. Still no response.

### Debugging Round 2

- Suspected wiring issues.
- Checked wires individually — found some loose connections.
- Rewired buttons exactly like in Arduino docs. Still no button detection.
- Took a break to reset and revisit later.

### Breakthrough (23/07)

- Found the actual bug: I was using the **pin number** (`buttonPin`) instead of the **read state** (`buttonState`) in the `if` conditions.
- Corrected the logic to use `buttonState1` and `buttonState2`.
- With wiring fixed and logic corrected, the program finally worked as intended.

---
## Outcome

- Pressing button 1 lights up the **green LED**.
- Pressing button 2 lights up the **blue LED**.
- Both buttons can be pressed simultaneously, and both LEDs light up accordingly.
- No delays; behaviour is immediate and real-time.

---
## Lessons Learned

- Always double-check whether you’re comparing a **pin number** or the **read state** variable in conditionals.
- Loose wiring can mimic software bugs — test hardware connections before rewriting code.
- Simple `if` branches are enough for this design; `while` loops would lock up the program.
- Debugging in hardware projects is often 50% wiring, 50% code.

---

✍️ This dev log was generated from code, in-code comments and raw dev notes, formatted and structured with AI assistance for clarity.  
For a full explanation of the workflow and AI use, see the README.