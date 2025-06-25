const int pushButtonPin = 2;
const int pwmLedPin = 9;

int ledLevelIndex = 0;
int currentButtonReading = 0;
int previousButtonReading = 0;

int ledBrightnessSteps[] = {0, 85, 170, 255};

void setup() {
  pinMode(pushButtonPin, INPUT_PULLUP);
  pinMode(pwmLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  currentButtonReading = digitalRead(pushButtonPin);

  if (currentButtonReading == LOW && previousButtonReading == HIGH) {
    ledLevelIndex = (ledLevelIndex + 1) % 4;  // Cycle through 0-3
    analogWrite(pwmLedPin, ledBrightnessSteps[ledLevelIndex]);

    Serial.print("Current LED brightness step: ");
    Serial.println(ledLevelIndex);

    delay(200);
  }

  previousButtonReading = currentButtonReading;
}
