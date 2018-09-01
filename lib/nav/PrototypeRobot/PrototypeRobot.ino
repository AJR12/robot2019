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
robot myRobot(motor1, motor2, motor3, motor4, 255); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
Navigate myNavigate(myRobot, sensors, imuSensor);


void setup() {
  Serial.begin(9600);
  imuSensor.bno.setExtCrystalUse(true);
  imuSensor.bno.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);

}

void loop() {


  //myNavigate.moveAll();
  //delay(2000);

  //sensors.printAll();

//  imuSensor.getInfo();
//  Serial.println(imuSensor.getPhi());
//  float phi = imuSensor.getPhi();
 myNavigate.moveFwd();
//  //myRobot.forwards(200);
//  display.setTextSize(2);
//  display.setTextColor(WHITE);
//  display.setCursor(0, 0);
//  display.println(phi);
//  display.setCursor(0, 20);
//  display.print(sensors.getDistanceFront());
//  display.setCursor(0, 40);
//  //display.print(x);
//  display.display();
//  //delay(100);
//  display.clearDisplay();

  // Serial.println(phi);

}
