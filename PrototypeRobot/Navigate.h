#ifndef Navigate_h
#define Navigate_h
#include "Arduino.h"
#include "robot.h"
#include "DistanceClass.h"

class Navigate 
{
  public:
       Navigate();
       Navigate(robot,DistanceClass);
       void moveRight();
       void moveLeft();
       void moveFwd();
       void moveBck();
       void moveAll();
       

  private:
      robot myRobot;
      DistanceClass mySensors;


};

#endif
