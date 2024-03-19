#include <Servo.h>

#define temperaturePin A1 // Analog pin for TMP36 sensor
#define microphonePin A0
#define cryThreshold 500 // Threshold for detecting crying (adjust as needed)
#define comfortThreshold 20 // Threshold for comfort temperature (adjust as needed)

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  // Read temperature from TMP36 sensor
  int rawTemperature = analogRead(temperaturePin);
  float voltage = rawTemperature * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100; // Convert to Celsius

  // Read sound level from simulated microphone (potentiometer)
  int soundLevel = analogRead(microphonePin);

  // If sound level is above cry threshold, simulate crying
  if (soundLevel > cryThreshold) {
    Serial.println("Baby is crying!");
    // Perform actions like sending notification or activating cradle rocking
    // For simplicity, let's just rock the cradle
    servo.write(90); // Assuming 90 degrees is the rocking position
    delay(1000); // Rocking time
    servo.write(0); // Return to initial position
  } else {
    // If sound level is below cry threshold, check temperature
    if (temperatureC > comfortThreshold) {
      Serial.println("Baby is not comfortable with the temperature. Adjust the temperature");
      // Perform actions like adjusting temperature or displaying a message
      // For simplicity, let's just print the temperature
      Serial.print("Temperature: ");
      Serial.print(temperatureC);
      Serial.println(" °C");
    } else {
      Serial.println("Baby is not crying. Temperature is comfortable.");
      // Perform actions like displaying a message or performing additional checks
      // For simplicity, let's just print the temperature
      Serial.print("Temperature: ");
      Serial.print(temperatureC);
      Serial.println(" °C");
    }
  }

  delay(2000); // Delay between sensor readings
}
