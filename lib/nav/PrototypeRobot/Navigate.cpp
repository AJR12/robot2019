#include "Arduino.h"
#include "Navigate.h"
#include "Imu.h"


Navigate::Navigate(robot robotic, DistanceClass robSensors, Imu phiSensor) {

  myRobot = robotic;
  mySensors = robSensors;
  imuSensor = phiSensor;



}

void Navigate::moveSquare()
{


  Serial.print("counter =");
  Serial.println(counter % 4);

  switch (counter % 4 ) {
    case 1:
      a = 0;
      Serial.println("case 1");

      break;
    case 2:
      a = 90;
      Serial.println("case 2");

      break;
    case 3:
      a = 180;

      break;
    case 0:
      a = 270;

      break;
    default:
      break;
  }

  Serial.println("test 2");
  int dist = mySensors.getDistanceFront();
  while (dist > 45) {
    myRobot.forwards(100, a);
    dist = mySensors.getDistanceFront();
    Serial.println("test 3 dist > 45");
    Serial.print("phi =");
    Serial.println(phi);
    Serial.print("dist =");
    Serial.println(dist);
  }

  myRobot.stopp();

  phi = imuSensor.getPhi();
  if (a != 270) {
    while ((phi < a + 89.5) && (phi > a + 90.5)) {

      myRobot.rotateLeft(100);
      phi = imuSensor.getPhi();
      Serial.println("test 7 turning left");
      Serial.print("phi =");
      Serial.println(phi);
    }
    Serial.println("test 8 stopped turning left");
    myRobot.stopp();
    counter++;
    return;

  } else {
    while ((phi < 359.5) && (phi > 0.5)) {
      myRobot.rotateLeft(100);
      phi = imuSensor.getPhi();
    }
    myRobot.stopp();
    counter++;
    return;
  }

}
