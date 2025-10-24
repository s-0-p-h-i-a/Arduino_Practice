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
| [RGB_LED_Photoresistor](https://github.com/s-0-p-h-i-a/Arduino_Practice/tree/main/RGB_LED_PR+BUTTONS) | Control an RGB LED via photoresistor and buttons, signal processing and PWM practice. |
| [Choose_LED_Photoresistor](https://github.com/s-0-p-h-i-a/Arduino_Practice/tree/main/Choose_LED_Photoresistor) | Control LEDs using a push button and a photoresistor. Handles single-input and dual-input scenarios, including blinking both LEDs when both inputs are active. Focus on boolean logic, analog/digital reading, and loop management. |
| [Choose_LED_Buttons](https://github.com/s-0-p-h-i-a/Arduino_Practice/tree/main/Choose_LED_Buttons) | Control LEDs using two physical buttons. Each button lights up a dedicated LED, with direct response to presses. Includes learning of wiring, input reading, and logical branching. |
| [Choose_LED_Serial](https://github.com/s-0-p-h-i-a/Arduino_Practice/tree/main/Choose_LED_Serial) | User chooses LED to light up via serial input. Includes input validation and LED feedback. |

---
## In Progress/Planned:

- **Hall Sensor Emulation:** RPM calculator using Hall sensor module, magnet and servo motor. PoC in progress.
- **Wheatstone Bridge Emulation:** breadboard components-based electricity learning practice.

---
## Tech Stack

- Elegoo Uno + basic breadboard components
- Sensor modules
- C++ (Arduino-flavoured)  
- Arduino IDE: Serial Monitor + Plotter

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


