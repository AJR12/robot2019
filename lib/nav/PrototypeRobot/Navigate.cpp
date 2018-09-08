#include "Arduino.h"
#include "Navigate.h"
#include "Imu.h"



Navigate::Navigate(robot robotic, DistanceClass robSensors, Imu phiSensor) {

  myRobot = robotic;
  mySensors = robSensors;
  imuSensor = phiSensor;
  

}

void Navigate::moveFwd(int angle,int pwm)
{
 myRobot.align(angle);
 myRobot.forwards(angle,pwm); 
}
