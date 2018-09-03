#ifndef Navigate_h
#define Navigate_h
#include "Arduino.h"
#include "robot.h"
#include "DistanceClass.h"
#include "Imu.h"

class Navigate 
{
  public:
       Navigate();
       Navigate(robot,DistanceClass,Imu);
       void moveFwd();
       void moveTurn();
       void rotateLeft();

       

  private:
      robot myRobot;
      DistanceClass mySensors;
      Imu imuSensor;
      int counter = 1;
      float phi;
      int a = 0;
      int c;
      int d;
      


};

#endif
