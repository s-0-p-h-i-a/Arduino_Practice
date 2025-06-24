# 🔩 **Arduino Projects — Embedded Systems Practice**

 This repository contains small Arduino-based projects I’ve developed as the first step of my hands-on learning in embedded systems, signal handling, and microcontroller programming. Each project focuses on understanding fundamental hardware–software interaction, building confidence with C++-based logic, and exploring real-world embedded use cases.

---
## 🎯 Goals

 - Practice input/output handling (serial, digital, analog)  
 - Explore embedded control structures with C++  
 - Gain experience with debugging physical system behaviour  
 - Develop relevant practical skills

---
## 📁 Project Structure

 Each project lives in its own folder and includes:
 - `.ino` source file(s)  
 - README and/or dev log with notes on development process  
 - Circuit diagram

---
## 📂 Projects

| Project | Description |
|--------|-------------|
| `choose_LED_serial` | User chooses LED to light up via serial input. Includes input validation and LED feedback. |
| *(Upcoming)* `choose_LED_buttons` | Use physical buttons instead of serial input to choose which LED to activate. |
| *(Upcoming)* `hall_sensor_emulator` | Emulates a flywheel Hall effect sensor using timed pulses. Intended for testing signal processing setups. |

---
## 🧪  Future Project Ideas

 - `choose_LED_buttons`: Replaces serial input with physical buttons. For learning debounce, pin reading, and interrupt-driven logic.  
 - `hall_sensor_emulator`: Simulate flywheel pulses for basic RPM calculator, including preventive mechanism that shuts off motor above defined RPM limit.

---
## 🛠️ Tech Stack

 - Elegoo Uno + basic breadboard components  
 - C++ (Arduino-flavoured)  
 - Serial Monitor

---
## 📚 Learning Approach

 - Start with basic functionality  
 - Isolate and debug input/output behaviour  
 - Add features incrementally  
 - Document reasoning, challenges, and solutions

---
## 📎 Notes on Code & Documentation

 - Manual raw note-taking during development  
 - AI-assisted polishing (README, dev logs)  
 - No code/text is published without full review  
 - Raw notes preserved for transparency and learning traceability

---

 **Built with curiosity, wires, and a solderless breadboard.**  
 _This repo documents my journey with first circuits to embedded systems_ 🛠️
