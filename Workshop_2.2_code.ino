// Define pin numbers
const int sensorPin = A1; // Analog pin connected to LDR (light sensor)
const int ledRed = 9;  // PWM pin for red LED
const int ledGreen = 10; // PWM pin for green LED
const int ledBlue = 11; // PWM pin for blue LED

// Define light thresholds for darkness and brightness
int darkThreshold = 800; // Above this value = dark 
int brightThreshold = 200; // Below this value = bright

void setup() {
  // Set LED pins as outputs
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the current light level from the LDR
  int lightValue = analogRead(sensorPin);

  // Print the reading to the Serial Monitor
  Serial.print("LDR Reading: ");
  Serial.println(lightValue);
  
  // Change LED color based on light level
  if (lightValue > darkThreshold) {
    // It's dark → show green
    updateColor(0, 250, 0);
    
  } else if (lightValue < brightThreshold) {
    // It's very bright → show red
    updateColor(255, 0, 0);
    
  } else {
    // It's ambient light → show blue
    updateColor(0, 0, 255);
  }

  // Small delay to prevent rapid flickering
  delay(200);
}

// Function to update LED color using PWM values
void updateColor(int redVal, int greenVal, int blueVal) {
  analogWrite(ledRed, redVal);  // Set brightness of red LED
  analogWrite(ledGreen, greenVal);  // Set brightness of green LED
  analogWrite(ledBlue, blueVal);  // Set brightness of blue LED
}
