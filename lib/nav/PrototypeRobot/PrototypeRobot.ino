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

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
uint8_t longRange = 2;//range for distance sensor up to 4m

Motor motor1(4, 22, 26);
Motor motor2(5, 34, 30);
Motor motor3(6, 38, 42);
Motor motor4(7, 52, 48);
DistanceClass sensors(31, 33, 41, 39, 37, 35, 42, 43);
VL53L1X distanceSensor; //laser sensor object6
Imu imuSensor;
robot myRobot(motor1, motor2, motor3, motor4, 255, imuSensor); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
Navigate myNavigate(myRobot, sensors, imuSensor);


void setup() {
  Serial.begin(9600);
  imuSensor.bno.setExtCrystalUse(true);
  imuSensor.bno.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();

  Serial.println("VL53L1X Qwiic Test");

  if (distanceSensor.begin() == false)
  {
    Serial.println("Sensor offline!");
  }
  distanceSensor.setDistanceMode(longRange);


}

void loop() {

  //  float phi = imuSensor.getPhi();
  //  float distance = distanceSensor.getDistance();
  Serial.println("Hello World");
  Serial.print("phi");
  Serial.println(imuSensor.getPhi());
  //  Serial.print("distance=");
  //  Serial.println(distance);


myRobot.forwards(150);

  //myRobot.align(45);
  //}


//  for (int i = 0; i < 100; i++) {
//
//    switch (i % 4) {
//      case 0:
//        myRobot.align(45);
//        delay(1000);
//        break;
//      case 1:
//        myRobot.align(135);
//        delay(1000);
//        break;
//      case 2:
//        myRobot.align(225);
//        delay(1000);
//        break;
//      case 3:
//        Serial.println("Entering case 3 in Main");
//        myRobot.align(315);
//        Serial.println("Left case 3 in Main");
//        delay(1000);
//
//        break;
//      default:
//        myRobot.stopp();
//    }
//  }
}





//  myRobot.align(180);

//  float phi = imuSensor.getPhi();
//  float distance = distanceSensor.getDistance();
//  Serial.print("phi");
//  Serial.println(imuSensor.getPhi());
//  Serial.print("distance=");
//  Serial.println(distance);

//  display.clearDisplay();
//  display.setTextSize(2);
//  display.setTextColor(WHITE);
//  display.setCursor(0,0);
//  display.print("Hello John");
//  display.setCursor(0,20);
//  display.print(imuSensor.getPhi());
//  display.setCursor(0,40);
//  display.print(distanceSensor.getDistance());
//  display.display();

//  myRobot.align(0);
//  Serial.print("level =");
//  Serial.println(1);
//  delay(2000);
//
//  myRobot.align(90);
//  Serial.print("level =");
//  Serial.println(2);
//  delay(2000);
//
//  myRobot.align(180);
//  Serial.print("level =");
//  Serial.println(3);
//  delay(2000);
//
//  myRobot.align(270);
//  Serial.print("level =");
//  Serial.println(4);
//  delay(2000);
//
//  myRobot.align(0);
//  Serial.print("level =");
//  Serial.println(5);
//  delay(2000);
//
//  myRobot.align(270);
//  Serial.print("level =");
//  Serial.println(6);
//  delay(2000);
//
//  myRobot.align(180);
//  Serial.print("level =");
//  Serial.println(7);
//  delay(2000);
//
//  myRobot.align(90);
//  Serial.print("level =");
//  Serial.println(8);
//  delay(2000);
//
//  myRobot.align(0);
//  Serial.print("level =");
//  Serial.println(9);
//  delay(2000);


//myNavigate.moveAll();
//delay(2000);

//sensors.printAll();


//  float phi = imuSensor.getPhi();
// myNavigate.moveSquare();
//  //myRobot.forwards(200);

//  display.clearDisplay();
//  display.setTextSize(2);
//  display.setTextColor(WHITE);
//  display.setCursor(0, 0);
//
//  display.println("test");
//  display.display();
//  display.setCursor(0, 20);
//  display.print(sensors.getDistanceFront());
//  display.setCursor(0, 40);
//  //display.print(x);

//  //delay(100);
//  display.clearDisplay();

// Serial.println(phi);


