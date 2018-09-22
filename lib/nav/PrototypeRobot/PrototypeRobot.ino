#include <vl53l1_register_map.h>
#include <SparkFun_VL53L1X_Arduino_Library.h>

#include "Arduino.h"
#include "robot.h"
#include "DistanceClass.h"
#include "Navigate.h"
#include "Imu.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
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
Imu imuSensor;
robot myRobot(motor1, motor2, motor3, motor4, 255, imuSensor); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
Navigate myNavigate(myRobot, sensors, imuSensor);
///  PID veriable
boolean findd = true;
double setPoint;
double input;
double output1;
double output2;
double kp = 5, ki = 0, kd = 0;

PID myPID(&input, &output1, &setPoint, kp, ki, kd, DIRECT);

//// End of the virable
void setup() {
  Serial.begin(9600);
  imuSensor.bno.setExtCrystalUse(true);
  imuSensor.bno.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.println("VL53L1X Qwiic Test");
  if (distanceSensor.begin() == false)
  {
    Serial.println("Sensor offline!");
  }
  distanceSensor.setDistanceMode(longRange);
  ///PID setup
  setPoint = 90;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(kp, ki, kd);

  //// end of setup PID

}

void loop() {


  displayy();

  if(findd){
    findthephi(setPoint);
    findd=false;
  }

  input = map(imuSensor.getPhi(), 0 , 360, 0, 255);
  //
  //  input = map(100, 0 , 360, 0, 255);
  //  input = imuSensor.getPhi();
  myPID.Compute();
  //  Serial.println(output1);


  myRobot.forwardAbdul( 150 , 150 + output1);

//  Serial.println(60 + output1);

  //      Serial.println(imuSensor.getPhi());
  //      Serial.print("  ");
  //      Serial.print(output1+60);
  //      Serial.println();
  //    Serial.println(output2);

}
void findthephi(int phi) {
  while (imuSensor.getPhi() < phi ) {
    myRobot.rotateLeft(100);
  }
  myRobot.stopp();
}


void displayy() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Hello John");
  display.setCursor(0, 20);
  display.print(imuSensor.getPhi());
  display.setCursor(0, 40);
  display.print(distanceSensor.getDistance());
  display.display();
}

