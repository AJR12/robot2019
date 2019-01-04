#include "Arduino.h"
#include "laser_ds.h"
#include <Wire.h>

Lasers lasers(13, 12, 11, 10);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin (115200);
  Serial.println("HELLO!!!");
  lasers.setAddy();
  lasers.i2cScan();
}

void loop() {
  
  int disF = lasers.sensF();
  int disB = lasers.sensB();
  int disL = lasers.sensL();
  int disR = lasers.sensR();
  
  Serial.print("disF = ");
  Serial.println(disF);
  Serial.print("disB = ");
  Serial.println(disB);
  Serial.print("disL = ");
  Serial.println(disL);
  Serial.print("disR = ");
  Serial.println(disR);
  delay(500);

}
