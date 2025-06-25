// Define pin numbers
const int pushButtonPin = 2; // Pushbutton input pin
const int pwmLedPin = 9; // PWM output pin connected to LED

// Variables for tracking LED brightness step and button state
int ledLevelIndex = 0; // Current brightness level index (0 to 4)
int currentButtonReading = 0; // Stores current state of the button
int previousButtonReading = 0; // Stores previous state to detect button press

// Array defining five brightness levels (including OFF and full brightness)
int ledBrightnessSteps[] = {0, 64, 128, 192, 255};

void setup() {
  pinMode(pushButtonPin, INPUT_PULLUP); // Set button pin as input with pull-up
  pinMode(pwmLedPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600); // Initialize serial monitor
}

void loop() {
  // Read current button state
  currentButtonReading = digitalRead(pushButtonPin);

  // Detect button press (falling edge)
  if (currentButtonReading == LOW && previousButtonReading == HIGH) {
    // Advance to next brightness level (cycle through 0–4)
    ledLevelIndex = (ledLevelIndex + 1) % 5;

    // Apply brightness level to LED
    analogWrite(pwmLedPin, ledBrightnessSteps[ledLevelIndex]);

    // Debug output
    Serial.print("Current LED brightness step: ");
    Serial.println(ledLevelIndex);

    // Delay for button debounce
    delay(200);
  }

  // Save current state for next loop
  previousButtonReading = currentButtonReading;
}
