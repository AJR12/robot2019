#include "Arduino.h"
#include "Imu.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#define BNO055_SAMPLERATE_DELAY_MS (100)


Imu::Imu() {}

void Imu::getInfo()
{
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  delay(BNO055_SAMPLERATE_DELAY_MS);
}

float Imu::getPhi()
{
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  float x = 360 - euler.x();
  if (x == 360.00){
    x=0;
  }
  delay(10);  
  return x;
}

