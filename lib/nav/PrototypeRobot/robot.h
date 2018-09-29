#ifndef robot_h
#define robot_h
#include "Arduino.h"
#include "motor.h"
#include "Imu.h"

class robot
{
  public:
    robot();
    robot(Motor motor1, Motor motor2, Motor motor3, Motor motor4, int Max);
    void align(int);
    void forwards(int, int);
    void forwardAbdul(int, int);
    void backwards(int);
    void stopp();
    void right(int);
    void moveInCircular(int );
    void rotateRight(int);
    void rotateLeft(int);
    void left(int);
    void diagonalLeftUp(int);
    void diagonalRightUp(int);
    void rightWheels(int);
    void leftWheels(int);
    void moveInCircle(double);
    void updateError();
    double wrap(double val, double min, double max);
    void initialize();
    double angle ;
    double error ;
    double desireAngle;
  private:
    moveInCircular1 (int, int);
    Motor _M1;
    Motor _M2;
    Motor _M3;
    Motor _M4;
    Imu imuSensor;
    int maxSpeed;
    float phi;
    




};

#endif
