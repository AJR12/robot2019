#include "Arduino.h"
#ifndef DistanceSensor_h
#define DistanceSensor_h



class DistanceSensor {
  public:
    DistanceSensor();
    DistanceSensor(int trig, int echo);
    int getDistance();


  private:
    int echoPin;
    int trigPin;
    int duration;
    int distance;



};
#endif
