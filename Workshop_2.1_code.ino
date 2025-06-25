// Define pin numbers
const int pushButtonPin = 2; // Pushbutton input pin (uses internal pull-up)
const int pwmLedPin = 9; // PWM output pin connected to LED

// Variables to manage LED brightness step index and button state
int ledLevelIndex = 0; // Current index for brightness level (0 to 3)
int currentButtonReading = 0; // Stores current reading from button
int previousButtonReading = 0; // Stores previous reading to detect button press

// Array of brightness levels (0 = off, 255 = Brightest level)
int ledBrightnessSteps[] = {0, 85, 170, 255};

void setup() {
  pinMode(pushButtonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(pwmLedPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  // Read the current state of the button
  currentButtonReading = digitalRead(pushButtonPin);

  // Check for a button press (transition from HIGH to LOW)
  if (currentButtonReading == LOW && previousButtonReading == HIGH) {
    ledLevelIndex = (ledLevelIndex + 1) % 4;  // Cycle through 0-3
    // Set the LED to the corresponding brightness level
    analogWrite(pwmLedPin, ledBrightnessSteps[ledLevelIndex]);

    Serial.print("Current LED brightness step: ");
    Serial.println(ledLevelIndex);
    // Small delay to debounce button press
    delay(200);
  }
  
   // Update the previous button state for next loop iteration
  previousButtonReading = currentButtonReading;
}
