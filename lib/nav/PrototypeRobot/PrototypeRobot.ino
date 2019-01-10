#include "Arduino.h"
#include <Wire.h>
#include "laser_ds.h"
#include "imu.h"
#include "oled.h"

#include "robot.h"
#include "Navigate.h"

Lasers lasers(13, 12, 11, 10); // (F, B, L, R)
Imu imu;
Oled oled;



Motor motor1(7, 24, 25);
Motor motor2(6, 28, 29);
Motor motor3(9, 34, 35);
Motor motor4(8, 38, 39);
//robot myRobot(motor1, motor2, motor3, motor4, 255, imuSensor); //robot(motor1, motor2, motor3, motor4, MaxSpeed)



void setup() {
  Wire.begin();
  Serial.begin(9600);

  //  Init Lasers dist sensors
  Serial.println("HELLO!!!");
  lasers.setAddy();
  lasers.i2cScan();

  //  Init IMU
  imu.start();

  //Init Oled
  oled.start();


}

void loop() {

  int disF = lasers.sensF();
  int disB = lasers.sensB();
  int disL = lasers.sensL();
  int disR = lasers.sensR();

  Serial.print("disF = ");
  Serial.println(disF);
  Serial.print("disB = ");
  Serial.println(disB);
  Serial.print("disL = ");
  Serial.println(disL);
  Serial.print("disR = ");
  Serial.println(disR);

  float phi = imu.getPhi();
  Serial.print("phi = ");
  Serial.println(phi);

//  delay(500);

oled.dispAll(phi, disF, disB, disL, disR);



  //
  //    float phi = imuSensor.getPhi();
  //  Serial.print("phi");
  //  Serial.println(imuSensor.getPhi());
  //    Serial.print("distance=");
  ////    Serial.println(distance);
  //  myRobot.forwards(100);
}
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
//}





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


