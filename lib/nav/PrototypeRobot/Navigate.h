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
       void moveFwdLeft(int);
       void moveSquare();
       void rotateLeft();

       

  private:
      robot myRobot;
      DistanceClass mySensors;
      Imu imuSensor;
      float phi;
      int a;
      int counter = 1;

      


};

#endif
