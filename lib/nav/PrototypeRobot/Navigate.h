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
<<<<<<< HEAD
       void moveFwdLeft(int);
       void moveSquare();
=======
       void moveFwd(int angl,int pw);
       void moveTurn();
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953
       void rotateLeft();

       

  private:
      robot myRobot;
      DistanceClass mySensors;
<<<<<<< HEAD
      Imu imuSensor;
      float phi;
      int a;
      int counter = 1;

=======
      Imu imuSensor;     
      int counter = 1;
      float phi;
      int a = 0;
      int c;
      int d;
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953
      


};

#endif
