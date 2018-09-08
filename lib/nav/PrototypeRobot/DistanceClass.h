#ifndef DistanceClass_h
#include "DistanceSensor.h"
#define DistanceClass_h


class DistanceClass
{
 public:
 DistanceClass();
 DistanceClass(int a,int b,int c,int d, int e,int f,int g,int h);
 long getDistanceFront();
 long getDistanceBack();
 long getDistanceRight();
 long getDistanceLeft();
 void printAll();

 private:

 DistanceSensor frontSensor;
 DistanceSensor backSensor;
 DistanceSensor rightSensor;
 DistanceSensor leftSensor;
  
   
};

#endif
