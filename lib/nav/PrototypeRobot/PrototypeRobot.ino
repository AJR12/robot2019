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
int pwm1 = 0;
int pwm2 = 0;
int st = 0;
robot myRobot(motor1, motor2, motor3, motor4, 255); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
Navigate myNavigate(myRobot, sensors);


void setup() {
  Serial.begin(9600);
   imuSensor.bno.setExtCrystalUse(true);;
}

void loop() {

  
  
  //myNavigate.moveAll();
  //delay(2000);

  //sensors.printAll();

  imuSensor.getInfo();


  //if (st < 2) {
  //    myRobot.moveInCircular(5) ; // take time delay
  //    myRobot.stopp();
  //    st++;
  //  }


  //
  //      myRobot.forwards(100);
  //      delay(2000);
  //  myRobot.right(100);
  //  delay(2000);
  //    myRobot.backwards(100);
  //    delay(2000);
  //  myRobot.left(100);
  //  delay(2000);
  //  myRobot.rotateLeft(100);
  //  delay(2000);
  //  myRobot.rotateRight(100);
  //  delay(2000);
  //
  //  myRobot.haults();
  //  delay(2000);

  //Serial.println("sf");
}
