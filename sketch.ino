// Define constants
const int lm35Pin = A0;  // LM35 sensor connected to Analog pin A0
const int ledPin = 13;   // Onboard LED connected to digital pin 13

// Define variables
unsigned long previousTime = 0;  // To store the last time LED was updated
int interval = 250;                // Blink interval for temperature below 30 degrees

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  Serial.begin(9600);       // Initialize serial communication for debugging
}

void loop() {
  // Read temperature from LM35 sensor
  int sensorValue = analogRead(lm35Pin);
  
  // Convert the analog sensor value to temperature in Celsius
  float temperatureC = (sensorValue * 0.0048828125) * 10.0;

  // Print temperature for debugging (optional)
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Check temperature conditions and control LED accordingly
  if (temperatureC < 30.0) {
    // Blink LED every 250 milliseconds
    blinkLED(250);
  } else {
    // Blink LED every 500 milliseconds
    blinkLED(500);
  }
}

void blinkLED(int blinkInterval) {
  unsigned long currentTime = millis();

  // Check if it's time to toggle the LED
  if (currentTime - previousTime >= blinkInterval) {
    // Save the current time
    previousTime = currentTime;

    // Toggle the LED state
    if (digitalRead(ledPin) == HIGH) {
      digitalWrite(ledPin, LOW);
    } else {
      digitalWrite(ledPin, HIGH);
    }
  }
}
