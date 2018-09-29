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

       

  private:
      robot myRobot;
      DistanceClass mySensors;
      Imu imuSensor;

      


};

#endif
