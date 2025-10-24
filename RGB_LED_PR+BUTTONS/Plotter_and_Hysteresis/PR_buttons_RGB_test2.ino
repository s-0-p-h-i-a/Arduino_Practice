/*
/*
RGB LED Control – Photoresistor + Buttons
-----------------------------------------
Goal:
Regulate RGB LED color based on photoresistor input, optional Serial input, and button toggles.

Hardware:
- RGB LED (common cathode), photoresistor on A0, optional buttons for R/G toggle.
- PWM pins used for all LED channels.

Behaviour:
- Photoresistor controls blue brightness (0–1023 → 0–255, inverted).
- Red and green LEDs respond to sensor thresholds and optional Serial-defined brightness.
- Buttons (if used) toggle red/green LEDs independently.
- Averaging current + last sensor reading smooths transitions and reduces flicker.
- Serial Plotter outputs sensor, average, and LED levels for visualization.

Code Structure:
- `setup()`: configure pins and Serial.
- `loop()`: read sensor, calculate average, map to RGB PWM levels, write to LEDs, send Serial data.
- Hysteresis simulated via discrete red/green activation ranges with buffer zones.

Debug / Experimentation Notes:
- PWM enabled for LED brightness; physical cutoff (~128) limits smooth control.
- Common cathode wiring required; common anode caused binary-like switching.
- Timing between Serial I/O and loop execution critical to avoid missed reads.
- Averaging improves smoothness; scaling needed for plotting visibility.
- Legacy if-checks for negative levels removed as they interfered with output.

Next Steps:
- Consider moving average for smoother hysteresis.
- Explore dynamic threshold definitions for R/G LEDs.
- Reintroduce buttons for manual override/mode switching.
*/


*/

const int redPin(4);
const int greenPin(3);
const int bluePin(2);

const int photoresistorPin(A0);


void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(photoresistorPin, INPUT);

  Serial.begin(9600);

}

int currentSensorValue = analogRead(photoresistorPin);

void loop() {



    int lastSensorValue = currentSensorValue;

    currentSensorValue = analogRead(photoresistorPin);
    int averageSensorValue = (currentSensorValue + lastSensorValue)/2;
    int redLevel = round(currentSensorValue * 255.0 /1023.0) - 100;
    //if (redLevel < 0) { redLevel = 0; }
    int greenLevel = round(currentSensorValue * 255.0 /1023.0) - 200;
    if (greenLevel < 0) { greenLevel = 0; }
    int blueLevel = 255 * (1.0 - currentSensorValue/1023.0);

    //bool redON   = analogRead(photoresistorPin) < 400;
    //bool greenON = analogRead(photoresistorPin) > 600 && analogRead(photoresistorPin) < 700;

    analogWrite(redPin, redLevel);
    analogWrite(greenPin, greenLevel);
    analogWrite(bluePin, blueLevel);


  double ratio(100.0/1023.0);
  Serial.print("Sensor_Value:");
  Serial.print(currentSensorValue*ratio);
  Serial.print(",");
  Serial.print("Average_Value:");
  Serial.println(averageSensorValue*ratio);
  Serial.print(",");
  Serial.print("Red_Level:");
  Serial.println((redLevel+200)*ratio);
  Serial.print(",");
  Serial.print("Green_Level:");
  Serial.println((greenLevel+400)*ratio);

}
