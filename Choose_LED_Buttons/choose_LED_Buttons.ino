// Choose LED via button input 06/07

// Idea: user chooses which LED to light up via button input. 2 buttons as input, 2 LEDs (green and blue) as output
// Process:
// - Copy&paste setup Choose LED via Serial code and refactor to pin the LEDs and buttons
// - Implementation questions: use while loops or if branches? Two separate instruction blocks for each button/LED?
//  Which works better if user wants to light up both LEDS? How would the code be processed with each option?
// - Logic decision: direct press button -> light LED response. If button is off, LED is also off. No delay for LED staying on after button press
// - 1st implementation: try with two separate if branches
// Did not work: first remove instructions to keep LEDS off. Did not work: try while loops.
// Did not work: add serial output code to check if button is being read
// Did not work for both buttons. No response on microcontroller when buttons are pressed: wiring issue
// Realised both LEDs were set up as input, fix that.
// Still no response from buttons press: disconnect and check wiring:
// - Check individual wires, some wires were a bit loose
// - Move button wiring to be exactly like in arduino documentation reference: still did not work
// -> leave further debugging for after lunch/another day

// 23/07
// Problem solved: was using buttonPin instead of buttonState for if branch condition



// DECLARATIONS: LED pin locations
const int greenPin = 13;
const int bluePin = 12;

// Button locations
const int buttonPin1 = 3;
const int buttonPin2 = 2;

// SETUP
void setup() {

  // Buttons setup
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  // LEDs setup
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}


void loop() {

  // Reset LEDs
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  // Reading buttons input
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH) {

    digitalWrite(greenPin, HIGH);

  } else {

    digitalWrite(greenPin, LOW);
  }

  if (buttonState2 == HIGH) {

    digitalWrite(bluePin, HIGH); 
    
  } else {

    digitalWrite(bluePin, LOW);
  }


}