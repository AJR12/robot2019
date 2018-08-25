#include "Arduino.h"
#include "Imu.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#define BNO055_SAMPLERATE_DELAY_MS (100)
#define BNO055_SAMPLERATE_DELAY_MS (100)

Imu::Imu(){}

void Imu::getInfo()
{
  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print(F("Orientation: "));
  Serial.print((float)event.orientation.x);
  Serial.print(F(" "));
  Serial.print((float)event.orientation.y);
  Serial.print(F(" "));
  Serial.print((float)event.orientation.z);
  Serial.println(F(""));

  delay(BNO055_SAMPLERATE_DELAY_MS);
}
