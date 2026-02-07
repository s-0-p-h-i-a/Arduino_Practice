// ^ = solved with AI assistance

// Choose LED via Serial Input — Summary (14–15/06)

// - Idea: Ask user which LED to light (1 = red, 2 = blue, 3 = green)
// - Process: LEDs off → input prompt → user selects → chosen LED lights up → turns off after delay
// - In case of invalid input: blinking LEDs + error message
// - Debugging:
//     - First attempt failed due to wiring + input misread
//     - ^ Fixed: used Serial.readStringUntil('\n') + toInt() for valid input
// - ^ Added input validation (flag + fallback behavior)
// - Noted timing issue: Serial input slower than main loop, caused unexpected second run due to newline
// - Output shows selected LED color (via switch) instead of raw number
// - LED turns off after delay — tested as optional cleanup step
// - Topics encountered: input timing, type casting from Serial.read, char vs string handling


// DECLARATIONS: LED pin locations
const int redPin = 13;
const int bluePin = 12;
const int greenPin = 11;

// SETUP
void setup() {

  // LEDs setup
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Serial monitor setup
  Serial.begin(9600); 

}

//// MAIN PROGRAM
void loop() {

  // Spacer
  Serial.println("☆");

  // Turn all LEDs off
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);

  //// INPUT
  // Ask user input
  Serial.println("Choose an LED: 1 = red, 2 = blue, 3 = green");

  // Pause until input
  while (Serial.available() == 0) { }

  // Read user input when received, skip newline
  String input = Serial.readStringUntil('\n');
  
  // Legacy: char answer = input.charAt(0);

  //// PROCESS
  // Convert input char to int
  int answer = input.toInt();

  // Input validation flag
  bool validInput = true;

  // Map answer to pin number
  int chosenPin;
  switch (answer) {

    case 1: chosenPin = redPin;
      break;
    
    case 2: chosenPin = bluePin;
      break;

    case 3: chosenPin = greenPin;
      break;

    default: validInput = false;
      break;
  }

  //// OUTPUT
  // Valid input
  if (validInput) {

    // Print chosen LED
    Serial.print("You chose the");
    switch (answer) {

    case 1: Serial.print(" red ");
      break;
    
    case 2: Serial.print(" blue ");
      break;

    case 3: Serial.print(" green ");
      break;

    default: Serial.print(" ? ");
      break;
  }
    Serial.println("LED.");

    // Light up chosen LED
    digitalWrite(chosenPin, HIGH);
    delay(3000);

    // Invalid input
    } else {

      // Spacer
      Serial.println("☆");
      // Error message
      Serial.println("Error! Invalid input");
      // Blink lights
      for (int i=0; i<3; ++i) {
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, HIGH);
        digitalWrite(redPin, HIGH);
        delay(200);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        digitalWrite(redPin, LOW);
        delay(200);
      }

    }

  // Turn LED back off
  digitalWrite(chosenPin, LOW);

  // Spacer
  Serial.println("☆");

}