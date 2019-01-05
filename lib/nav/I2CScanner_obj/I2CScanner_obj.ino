#include <Arduino.h>
#include <Wire.h>
#include "i2c.h"
I2C i2c;

void setup() {
  Wire.begin();
Serial.begin(9600);
}

void loop() {

delay(500);
i2c.scan();

}

