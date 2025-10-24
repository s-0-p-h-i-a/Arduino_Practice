/*
PHOTORESISTOR + BUTTONS = RGB
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
- RGB LED behaves as if it does not support true brightness control (binary ON/OFF cutoff ~128)
- Timing issues caused Serial input lag and missed reads
- Adjusted delay placement (before/after getLevel) to synchronise Serial I/O and logic flow
- Learned to identify delay-related I/O timing interference and manual workaround points.

*/

const int redPin(13);
const int greenPin(12);
const int bluePin(11);

const int photoresistorPin(A0);
const int button1Pin(6);
const int button2Pin(5);


void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(photoresistorPin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  Serial.begin(9600);

}

int getLevel(String colour);

void loop() {

  // SERIAL INPUT READ
  delay(3000);

  int redLevel = getLevel("red");

  delay(3000);

  int greenLevel = getLevel("green");

  delay(3000);

  // PAUSE REST OF PROGRAM AND STAY IN LOOP WITH STATIC RED&GREEN BRIGHTNESS
  // UNTIL SERIAL INPUT TO QUIT & START OVER
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

int getLevel(String colour) {

  int level(0);
  bool validInput(true);
  do {
    Serial.println("Enter desired brightness % for " + colour + " pin:");
    delay(1000);
    level = Serial.parseInt();
    delay(1000);
    validInput = level >= 0 && level <= 100;

    if (!validInput) {
      Serial.println("Invalid input! Must be in the 0-100 range");
    }

  } while (!validInput);

  level = round(level * 2.55);

  while (Serial.available() > 0) {
    Serial.read(); // discard leftover bytes
  }

  Serial.println(level);

  return level;

}
