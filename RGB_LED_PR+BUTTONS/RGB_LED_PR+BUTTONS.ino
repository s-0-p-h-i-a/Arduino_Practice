/*
PHOTORESISTOR + BUTTONS = RGB (Final Version)
-----------------------------------------
Goal:
Control an RGB LED using two buttons and a photoresistor, based on digital input logic.

Behaviour:
- Button 1 → toggles red LED
- Button 2 → toggles green LED
- Photoresistor → toggles blue LED (active when light < threshold)
- Each LED outputs full ON/OFF levels (no PWM brightness control)

Structure:
- Read button and photoresistor states each loop cycle
- Use simple boolean-to-int mapping (ON/OFF = 255/0) for clarity
- Write LED states using ternary expressions for compactness.

Notes:
- Earlier version included Serial-based brightness control and dynamic blue level adjustment.
- Hardware testing revealed LED pins only support binary output (no brightness gradation).
- Simplified final implementation improves reliability and code clarity.
- This version focuses on stable digital logic, clean pin management, and consistent I/O behaviour.

Takeaways:
- Verified effects of analog read thresholds and wiring stability.
- Observed timing and interference issues from Serial I/O in hardware.
- Demonstrated practical debugging flow: start from full behaviour, then isolate stable logic paths.
*/


const int redPin(13);
const int greenPin(12);
const int bluePin(11);

const int photoresistorPin(A0);
const int button1Pin(6);
const int button2Pin(5);

const int ON(255);
const int OFF(0);

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(photoresistorPin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

}

void loop() {

  bool button1ON = digitalRead(button1Pin);
  bool button2ON = digitalRead(button2Pin);
  bool photoresistorActive = analogRead(photoresistorPin) < 450;

  analogWrite(redPin,   button1ON ? ON : OFF);
  analogWrite(greenPin, button2ON ? ON : OFF);
  analogWrite(bluePin,  photoresistorActive ? ON : OFF);

}
