#include <Arduino.h>

const float totalResistance = 10000;
const float maxADCValue = 1023;


void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  int sensorValue = analogRead(A0); // read the input on analog pin A0
  
  if (sensorValue > maxADCValue) {
    sensorValue = maxADCValue;
  }

  float curResistance = sensorValue / maxADCValue * totalResistance;

  Serial.print("ADC: ");
  Serial.print(sensorValue);
  Serial.print(" | Resistance: ");
  Serial.print(curResistance, 1); // 1 decimal place
  Serial.println(" Ohm");


  delay(10); // wait 10 milliseconds before the next reading
}
