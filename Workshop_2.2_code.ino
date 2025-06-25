const int sensorPin = A1;
const int ledRed = 9;
const int ledGreen = 10;
const int ledBlue = 11;

int darkThreshold = 800;   
int brightThreshold = 200;  

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(sensorPin);
  Serial.print("LDR Reading: ");
  Serial.println(lightValue);

  if (lightValue > darkThreshold) {
    updateColor(0, 250, 0);
  } else if (lightValue < brightThreshold) {
    updateColor(255, 0, 0);
  } else {
    updateColor(0, 0, 255);
  }

  delay(200);
}

void updateColor(int redVal, int greenVal, int blueVal) {
  analogWrite(ledRed, redVal);
  analogWrite(ledGreen, greenVal);
  analogWrite(ledBlue, blueVal);
}
