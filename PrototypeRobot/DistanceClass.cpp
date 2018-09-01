#include "Arduino.h"
#include "DistanceClass.h"
#include "DistanceSensor.h"

DistanceClass::DistanceClass() {}
DistanceClass::DistanceClass(int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1) {
  DistanceSensor front(a1, b1);
  DistanceSensor back(c1, d1);
  DistanceSensor right(e1, f1);
  DistanceSensor left(g1, h1);

  frontSensor = front;
  backSensor = back;
  rightSensor = right;
  leftSensor = left;

}

long DistanceClass::getDistanceFront()
{
  return frontSensor.getDistance();
}

long DistanceClass::getDistanceBack()
{
  return backSensor.getDistance();
}

long DistanceClass::getDistanceRight()
{
  return rightSensor.getDistance();
}

long DistanceClass::getDistanceLeft()
{
  return leftSensor.getDistance();
}

void DistanceClass::printAll()
{

long f = frontSensor.getDistance();
long b = backSensor.getDistance();
long r = rightSensor.getDistance();
long l = leftSensor.getDistance();
Serial.print("front :" + f);
Serial.print(" Back :" + b);
Serial.print(" Right :" + r);
Serial.print(" Left :" + l);

}
