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
//#include "VL53L1X.h" //Laser Sensor library
#include "SparkFun_VL53L1X_Arduino_Library.h"
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
<<<<<<< HEAD
uint8_t longRange = 2;//range for distance sensor up to 4m
=======
VL53L1X distanceSensor; //laser sensor object
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953

uint8_t longRange = 2;//range for distance sensor up to 4m

Motor motor1(3, 28, 30);//pwm for bck
Motor motor2(4, 32, 26);
Motor motor3(5, 34, 40);
Motor motor4(6, 38, 36);
DistanceClass sensors(31, 33, 41, 39, 37, 35, 42, 43);
VL53L1X distanceSensor; //laser sensor object
Imu imuSensor;
<<<<<<< HEAD
robot myRobot(motor1, motor2, motor3, motor4, 255, imuSensor); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
=======
robot myRobot(motor1, motor2, motor3, motor4, 255,imuSensor); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953
Navigate myNavigate(myRobot, sensors, imuSensor);
int distance =0;





void setup() {
  Wire.begin();
  Serial.begin(9600);
  //initializing IMU
  imuSensor.bno.setExtCrystalUse(true);
  imuSensor.bno.begin();
  //initializing Oled display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
<<<<<<< HEAD
  display.display();
=======
  pinMode(48,OUTPUT);
  digitalWrite(48,HIGH);
  //initializing laser sensor
  
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953
  Serial.println("VL53L1X Qwiic Test");

  if (distanceSensor.begin() == false)
  {
    Serial.println("Sensor offline!");
  }
  distanceSensor.setDistanceMode(longRange);
<<<<<<< HEAD

=======
  delay(2000);
  
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953

}

void loop() {
  //float x = imuSensor.getInfo();
//  Serial.println(x);
//  Serial.print("In Main loop x =");
//  Serial.println(x);
  //Poll for completion of measurement. Takes 40-50ms.
//  while (distanceSensor.newDataReady() == false)
//    delay(5);
//
 distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor 
  Serial.println(imuSensor.getPhi());
  //myNavigate.moveFwd(45,100);
//  PrintOled();




}




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


<<<<<<< HEAD
  //myNavigate.moveAll();
  //delay(2000);

  //sensors.printAll();
  float phi = imuSensor.getPhi();
  float distance = distanceSensor.getDistance();
  Serial.print("phi");
  Serial.println(imuSensor.getPhi());
  Serial.print("distance=");
  Serial.println(distance);
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
=======
void PrintOled()
{
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Dist:");
  display.print(distance);
  display.setCursor(0, 20);
  display.print("ang:" );
  display.print(imuSensor.getAngle());
  display.display();
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953

}
