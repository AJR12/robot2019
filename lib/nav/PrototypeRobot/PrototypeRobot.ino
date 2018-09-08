#include "Arduino.h"
#include "robot.h"
#include "DistanceClass.h"
#include "Navigate.h"
#include "Imu.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "VL53L1X.h" //Laser Sensor library
//#include "SparkFun_VL53L1X_Arduino_Library.h"
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
//VL53L1X distanceSensor; //laser sensor object
VL53L1X Distance_Sensor;

uint8_t longRange = 2;//range for distance sensor up to 4m

Motor motor1(3, 28, 30);//pwm for bck
Motor motor2(4, 32, 26);
Motor motor3(5, 34, 40);
Motor motor4(6, 38, 36);
DistanceClass sensors(31, 33, 41, 39, 37, 35, 42, 43);
Imu imuSensor;
robot myRobot(motor1, motor2, motor3, motor4, 255, imuSensor); //robot(motor1, motor2, motor3, motor4, MaxSpeed)
Navigate myNavigate(myRobot, sensors, imuSensor);
int distance = 0;





void setup() {
  Wire.begin();
  Wire.setClock(400000);
  Serial.begin(9600);
  if (!Distance_Sensor.init())
  {
    Serial.println("Failed to initialize VL53L1X Distance_Sensor!");
    while (1);
  }
  Distance_Sensor.setDistanceMode(VL53L1X::Long);
  Distance_Sensor.setMeasurementTimingBudget(50000);
  Distance_Sensor.startContinuous(50);
  //initializing IMU
  imuSensor.bno.setExtCrystalUse(true);
  imuSensor.bno.begin();
  //initializing Oled display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(48, OUTPUT);
  digitalWrite(48, HIGH);
  //initializing laser sensor


  delay(2000);


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
  //distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  //Serial.println(imuSensor.getPhi());
  //myNavigate.moveFwd(45,100);
  Serial.println(imuSensor.getPhi());
  Distance_Sensor.read();
  Serial.print("Distance(mm): ");
  Serial.print(Distance_Sensor.ranging_data.range_mm);
  Serial.println();
  
  PrintOled();




}





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

}
