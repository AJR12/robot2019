#include "Arduino.h"
#include "laser_ds.h"
#include <Wire.h>

Lasers lasers(13, 12,11,10);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin (115200);
  Serial.println("HELLO!!!");
  lasers.setAddy();
  lasers.i2cScan();
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensF = lasers.sensF();
  int sensB = lasers.sensB();
  Serial.print("sensF = ");
  Serial.println(sensF);
    Serial.print("sensB = ");
  Serial.println(sensB);
  delay(1000);

}
