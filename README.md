# **Arduino Projects — Embedded Systems Practice**

This repository contains small Arduino-based projects I’ve developed as the first step of my hands-on learning in embedded systems, signal handling, and microcontroller programming. Each project focuses on understanding fundamental hardware–software interaction, building confidence with C++-based logic, and exploring real-world embedded use cases.

---
## Goals

- Practice input/output handling (serial, digital, analog)  
- Explore embedded control structures with C++  
- Gain experience with debugging physical system and code behaviour

---
## Project Structure

Each project lives in its own folder and includes:  
- `.ino` source file(s)  
- README and dev log with notes on development process  
- Diagrams folder with demo GIF, wiring diagram and circuit schematic 

---
## Projects

| Project | Description |
|--------|-------------|
| `choose_LED_serial` | User chooses LED to light up via serial input. Includes input validation and LED feedback. |
| `choose_LED_buttons` | Control LEDs using two physical buttons. Each button lights up a dedicated LED, with direct response to presses. Includes learning of wiring, input reading, and logical branching. |
| `choose_LED_buttons_photoresistor` | Control LEDs using a push button and a photoresistor. Handles single-input and dual-input scenarios, including blinking both LEDs when both inputs are active. Focus on boolean logic, analog/digital reading, and loop management. |

---
## Future Project Ideas

- `hall_sensor_emulator`: Simulate flywheel pulses for basic RPM calculator, including preventive mechanism that shuts off motor above defined RPM limit.

---
## Tech Stack

- Elegoo Uno + basic breadboard components  
- C++ (Arduino-flavoured)  
- Serial Monitor  

---
## Learning Approach

- Start with basic functionality  
- Isolate and debug input/output behaviour  
- Add features incrementally  
- Document reasoning, challenges, and solutions

---
## Notes on Code & Documentation

- Manual raw note-taking during development  
- AI-assisted polishing (README, dev logs)  
- No code/text is published without full review

---

**Built with curiosity, wires, and a solderless breadboard.**  
_This repo documents my journey from first circuits to embedded systems._

