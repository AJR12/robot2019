#include "Arduino.h"
#include <Wire.h>
#include "imu.h"
Imu imu;


#include "oled.h"

Oled oled;

void setup() {
  Serial.begin(9600);
  imu.start();


}

void loop() {
  float phi = imu.getPhi();
  Serial.print("phi = ");
  Serial.println(phi);

  oled.dispPhi(phi);

}
