// Choose LED via button or photoresistor input 24/07

// - Found new way of writing comments with two fw slash pair // // to separate groups of intruction blocks

// - Idea: use recently learned boolean arithmetic concepts to create flag variables
//  Potential issue: boolean variables would not change after being initially defined: LEDs would get stuck on/blinking?
//  But: the variables get defined again at every loop, so it might work

// - Idea: writing only the cases where a LED has to turn on, and turn both off at the end or start of loop?
// - Implementation:
//    - 2 separate if branches at the start of main loop to turn off LED(s) if no input
//    - Then 3 if - else if branches for PR only, button only, and both
//    - Total of 5 instruction blocks instead of 6, and only 3 of them are interconnected
//    - No input (from either source) cases are handled individually at the start: clean reset checkpoint at every loop

// Update: was no aware that Arduino C++ has boolean variables, will use them in the future. Leaving int "booleans" here to reflect learning process


// // DECLARATIONS:
// LED pin locations
const int greenLED = 13;
const int blueLED = 12;

// Input locations
const int buttonPin = 2;
const int sensorPin = A0;

// // SETUP
void setup() {

  // Buttons setup
  pinMode(buttonPin, INPUT);
  pinMode(sensorPin, INPUT);

  // LEDs setup
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

}

// // MAIN LOGIC
void loop() {

  // // READING INPUT
  int buttonState = digitalRead(buttonPin);
  int value = analogRead(sensorPin);

  // // BOOLEAN VARIABLES
  // Photoresistor state
  int photoresistorLOW = (value <= 450);

  // Photoresistor only
  int photoresistorONLY = photoresistorLOW * !buttonState;

  // Button only
  int buttonONLY = !photoresistorLOW * buttonState;

  // Both inputs = 
  int bothInputs = photoresistorLOW * buttonState;

  // // RESET LEDS
  if (!buttonState) {
    digitalWrite(blueLED, LOW);
  }

  if (!photoresistorLOW) {
    digitalWrite(greenLED, LOW);
  }

  // // START: turn LEDs on if input
  // Photoresistor only
  if (photoresistorONLY) {

    digitalWrite(greenLED, HIGH);

  }
  
  // Button only
  else if (buttonONLY) {

    digitalWrite(blueLED, HIGH);

  }
  
  // Both inputs
  else if (bothInputs) {

    // Blink loop
    while (buttonState == HIGH && value <= 450) {

      // LEDs ON
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, HIGH);
      delay(200);

      // LEDs OFF
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
      delay(100);

      // Reset input readings
      buttonState = digitalRead(buttonPin);
      value = analogRead(sensorPin);

    }
  }

}




