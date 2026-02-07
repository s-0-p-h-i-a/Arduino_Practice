# Digital Logic Practice — Arduino Sensor Project

A digital logic and Boolean algebra exercise based on my Arduino **photoresistor + button** project.  
The goal is to simulate the Arduino sketch’s behaviour using only **logic gates** (no code), analyze the resulting logic function, and strengthen the conceptual bridge between **program control flow** and **circuit-level logic**.

---
## Overview

This project connects two domains:

1. **Arduino sketch (software)** — real-time behaviour controlled by code loops and conditionals.

2. **Logic circuit (hardware)** — equivalent behaviour expressed entirely through combinational logic.

It’s part of my effort to apply **digital logic and Boolean algebra** concepts from my _Computer Systems_ course to a real embedded context.

---
## Part 1: Logic Circuit Design

### Goal

Recreate the Arduino circuit’s behaviour using only **logic gates**, without any microcontroller or programming.

### Approach

- Translated the **photoresistor + button** circuit into a **logic simulation**.

- Replaced time-based code behaviour (e.g. blinking) with a **signal generator** acting as a third input.

- Implemented blinking using **AND** and **XOR** gates to model alternating high/low signals.

### Challenge

Simulating **blinking** purely with logic was non-trivial. The solution was to introduce a generator that toggles on/off periodically — effectively emulating Arduino’s `loop()` behaviour through hardware logic alone.

**Observation:**  
Although the visible LED behaviour matched the Arduino sketch, the **phase was inverted** — LEDs were LOW when the generator was HIGH, and vice versa.

### Takeaways

- Strengthened applied understanding of **combinational logic**.

- Learned what a **generator** is and how to conceptualise it in real-time terms.

- Gained intuition for bridging **loop-based software behaviour** with **hardware timing**.

### Circuit:

Diagrams of the combinational circuit under different input combinations:
- [Part 1](./Part1.md)

---
## Part 2: Boolean Function Analysis

### Goal

Analyze the logic circuit’s behaviour mathematically to reinforce Boolean algebra concepts.

### Approach

- Defined input/output vectors corresponding to the circuit’s real-time states.

- Created a **truth table** and intermediary logic functions.

- Derived the main function using **AND, OR, NOT** expressions.

- Planned additions: **minterms, maxterms, SOP/POS forms, Karnaugh maps**, and **reduced expressions**.

### Takeaways

- Practiced deriving mathematical representations of real-world logic circuits.

- Developed a deeper understanding of how **alternating outputs** (like a blinking LED) fit into **combinational logic models**.

- Built an intuitive connection between **mathematical abstraction** and **physical behaviour**.

### Analysis:

Truth tables and function analysis:
- [Part 2](./Part2.md)

---
## From Code to Circuit: Key Learnings

|Topic|Arduino Side|Logic Circuit Side|
|---|---|---|
|Behaviour control|`loop()` + conditionals|Signal generator + gate logic|
|Input handling|Analog threshold (PR)|Logic level HIGH/LOW|
|Debugging|Conditional branches|Gate path verification|
|Timing|Software delay|Generator frequency|
|Insight gained|Handling real-time input|Visualising clock-like behaviour|
