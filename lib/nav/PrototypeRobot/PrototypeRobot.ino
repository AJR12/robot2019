#include <vl53l1_register_map.h>
#include <SparkFun_VL53L1X_Arduino_Library.h>

#include "Arduino.h"
#include "robot.h"
#include "DistanceClass.h"
#include "Navigate.h"
#include "Imu.h"
#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <PID_v1.h>  // PID
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);

uint8_t longRange = 2;//range for distance sensor up to 4m

Motor motor1(3, 24, 25);
Motor motor2(4, 28, 29);
Motor motor3(5, 32, 33);
Motor motor4(6, 36, 37);
DistanceClass sensors(31, 33, 41, 39, 37, 35, 42, 43);
VL53L1X distanceSensor; //laser sensor object
//Imu imuSensor;
robot myRobot(motor1, motor2, motor3, motor4, 255); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
//Navigate myNavigate(myRobot, sensors, imuSensor);
///  PID veriable
boolean findd = true;
double setPoint;
double input;
double output1;
double output2;
double kp = 7, ki = 0, kd = 0 ;

PID myPID(&input, &output1, &setPoint, kp, ki, kd, DIRECT);

//// End of the virable
void setup() {
  Serial.begin(115200);
  
//  imuSensor.bno.setExtCrystalUse(true);
//  imuSensor.bno.begin();
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.println("VL53L1X Qwiic Test");
  if (!distanceSensor.begin())
  {
    Serial.println("Sensor offline!");
  }
  distanceSensor.setDistanceMode(longRange);

  ///PID setup
  setPoint = 90;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(kp, ki, kd);
  //// end of setup PID
  myRobot.initialize();
}

//double integral;
double angle;
double error = 0;
void loop() {
  
  myRobot.moveInCircle(0.1);
//  Serial.println("G");
  displayy();
  
//
//  if (findd) {
//    findthephi(setPoint);
//    findd = false;
//  }
//  setPoint = wrap(setPoint + 3, 0, 360);
//  updateError();
//  double diff = error * 5;
//  double max_v = 100;
//  if (diff > max_v)diff = max_v; else if (diff < -max_v)diff = -max_v;
//
//  displayy();
//
//  myRobot.forwardAbdul( 150 - diff , 150 + diff);

//}

//void updateError(){
//  angle = imuSensor.getPhi();
//  error = wrap(angle-setPoint, -180, 180);
//}

//void findthephi(int phi) {
//  int find_accuracy = 2;
//  while (abs(error) > find_accuracy ) {
//    updateError();
//    if (error > 0)
//      myRobot.rotateLeft(100);
//    else if (error < 0)
//      myRobot.rotateRight(100);
//  }


//  while (angle < phi - find_accuracy && angle > phi + find_accuracy ) {
//    angle = imuSensor.getPhi();
//    if ((phi + 180) < 360) {
//      if (angle > (phi - find_accuracy) && angle < (phi + 180)) {
//        myRobot.rotateRight(100);
//      } else {
//        myRobot.rotateLeft(100);
//      }
//    } else if ((phi - 180) > 0) {
////      if (angle < (phi + find_accuracy) && angle > (phi - 180)) {
////        myRobot.rotateRight(100);
////      } else {
////        myRobot.rotateLeft(100);
////      }
////    }
////  }

  myRobot.stopp();
}

void goStraight(int angle){
  
}
void goInCircle(){
  
}
double wrap(double val, double min, double max){
  double range = max - min;
  if (val < min)
    val += range;
  else if (val > max)
    val -= range;
  return val;
}

void displayy() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print(myRobot.error);
  display.setCursor(0, 20);
  display.print(myRobot.angle);
  display.setCursor(0, 40);
  display.print(myRobot.desireAngle);
  display.display();
}

