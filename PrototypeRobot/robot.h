#ifndef robot_h
#define robot_h
#include "Arduino.h"
#include "motor.h"


class robot
{
  public:
  robot();
    robot(Motor motor1, Motor motor2, Motor motor3, Motor motor4, int Max);
    void forwards(int);
    void backwards(int);
    void stopp();
    void right(int);
    void moveInCircular(int );

    void rotateRight(int);

    void rotateLeft(int);
    void left(int);
    void diagonalLeftUp(int);
    void diagonalRightUp(int);
  private:
    moveInCircular1 (int, int);
    Motor _M1;
    Motor _M2;
    Motor _M3;
    Motor _M4;
    int maxSpeed;



};

#endif
