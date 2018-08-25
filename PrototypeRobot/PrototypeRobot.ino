#include "Arduino.h"
#include "robot.h"
#include "DistanceClass.h"
#include "Navigate.h"
#include "Imu.h"

Motor motor1(3, 30, 28);
Motor motor2(4, 26, 32);
Motor motor3(5, 34, 40);
Motor motor4(6, 38, 36);
DistanceClass sensors(31, 33, 41, 39, 37, 35, 42, 43);
Imu imuSensor;
robot myRobot(motor1, motor2, motor3, motor4, 255); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
Navigate myNavigate(myRobot, sensors);


void setup() {
  Serial.begin(9600);  
   imuSensor.bno.setExtCrystalUse(true);
   imuSensor.bno.begin();
}

void loop() { 
  
  //myNavigate.moveAll();
  //delay(2000);
  
  //sensors.printAll();

  imuSensor.getInfo();

}
