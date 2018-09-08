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

Motor motor1(3, 30, 28);
Motor motor2(4, 26, 32);
Motor motor3(5, 34, 40);
Motor motor4(6, 38, 36);
DistanceClass sensors(31, 33, 41, 39, 37, 35, 42, 43);
Imu imuSensor;
robot myRobot(motor1, motor2, motor3, motor4, 255, imuSensor); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
Navigate myNavigate(myRobot, sensors, imuSensor);


void setup() {
  Serial.begin(9600);
  imuSensor.bno.setExtCrystalUse(true);
  imuSensor.bno.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  delay(2000);


}

void loop() {

  myRobot.align(0);
  Serial.print("level =");
  Serial.println(1);
  delay(2000);

  myRobot.align(90);
  Serial.print("level =");
  Serial.println(2);
  delay(2000);

  myRobot.align(180);
  Serial.print("level =");
  Serial.println(3);
  delay(2000);

  myRobot.align(270);
  Serial.print("level =");
  Serial.println(4);
  delay(2000);

  myRobot.align(0);
  Serial.print("level =");
  Serial.println(5);
  delay(2000);

  myRobot.align(270);
  Serial.print("level =");
  Serial.println(6);
  delay(2000);

  myRobot.align(180);
  Serial.print("level =");
  Serial.println(7);
  delay(2000);

  myRobot.align(90);
  Serial.print("level =");
  Serial.println(8);
  delay(2000);

  myRobot.align(0);
  Serial.print("level =");
  Serial.println(9);
  delay(2000);


  //myNavigate.moveAll();
  //delay(2000);

  //sensors.printAll();

  imuSensor.getInfo();
  //  Serial.println(imuSensor.getPhi());
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

}
