//#include <vl53l1_register_map.h>
//#include "Arduino.h"
//#include "robot.h"
//#include "DistanceClass.h"
//#include "Imu.h"
//#include <Wire.h>
//#include <Adafruit_GFX.h>

#include <SparkFun_VL53L1X_Arduino_Library.h>
#include "Navigate.h"
#include <Adafruit_SSD1306.h>
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
  myRobot.goStraightTo(180);
  displayy();
}


void displayy() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  //  display.print(error);
  display.setCursor(0, 20);
  //  display.print(angle);
  display.setCursor(0, 40);
  //  display.print(setPoint);
  display.display();
}





