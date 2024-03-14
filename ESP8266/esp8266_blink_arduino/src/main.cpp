#include "core_esp8266_features.h"
#include "pins_arduino.h"
#include <Arduino.h>


 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN_AUX, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  // delay(500);

  digitalWrite(LED_BUILTIN_AUX, HIGH);
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  // delay(500);

  digitalWrite(LED_BUILTIN_AUX, LOW);
  delay(1000);
}
