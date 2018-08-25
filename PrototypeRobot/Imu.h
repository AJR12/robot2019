#ifndef Imu_h
#define Imu_h
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

class Imu
{
  public:
    Imu();
    
    void getInfo();
    Adafruit_BNO055 bno = Adafruit_BNO055(55);
};

#endif
