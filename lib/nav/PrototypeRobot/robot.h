#ifndef robot_h
#define robot_h
#include "Arduino.h"
#include "motor.h"
#include "Imu.h"

class robot
{
  public:
    robot();
    robot(Motor motor1, Motor motor2, Motor motor3, Motor motor4, int Max, Imu);
    void forwards(int);
    void backwards(int);
    void stopp();
    void right(int);
    void rotateRight(int);
    void rotateLeft(int);
    void left(int);
    void diagonalLeftUp(int);
    void diagonalRightUp(int);
    void goStraightTo(int desire);
    void goInCircle(double increase);
   
  private:
   void forwardAbdul(int , int) ;
   double wrap(double val, double min, double max) ;
    
    Motor _M1;
    Motor _M2;
    Motor _M3;
    Motor _M4;
    Imu imuSensor;
    int maxSpeed;
    float phi;
    double angle;
    double error = 0;
    double setPoint = 90;



};

#endif
