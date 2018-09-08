#include "Arduino.h"
#include "Navigate.h"
#include "Imu.h"



Navigate::Navigate(robot robotic, DistanceClass robSensors, Imu phiSensor) {

  myRobot = robotic;
  mySensors = robSensors;
  imuSensor = phiSensor;
  



}

<<<<<<< HEAD
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


//void Navigate::moveFwdLeft(int counter)
//{
//
//
//
//  Serial.println("test 1");
//
//  Serial.println(mySensors.getDistanceFront());
//  int dist = mySensors.getDistanceFront();
//  while ( mySensors.getDistanceFront() > 45)
//  {
//    Serial.println("test 2");
//
//    phi = imuSensor.getPhi();
//    myRobot.forwards(100, a);
//    Serial.print("Angle = ");
//    Serial.println(phi);
//    Serial.print("a = ");
//    Serial.println(a);
//    Serial.print("c = ");
//    Serial.println(c);
//    Serial.print("d = ");
//    Serial.println(d);
//    Serial.println(counter);
//    Serial.print("distance = ");
//    Serial.println(mySensors.getDistanceFront());
//  }
//  Serial.println("Test 3");
//  Serial.print("Angle = ");
//  Serial.println(phi);
//  Serial.print("a = ");
//  Serial.println(a);
//  Serial.print("c = ");
//  Serial.println(c);
//  Serial.print("d = ");
//  Serial.println(d);
//  Serial.println(counter);
//  Serial.print("distance = ");
//  Serial.println(mySensors.getDistanceFront());
//  myRobot.stopp();
//  if (counter != 4) {
//    while (phi < a + 90)
//    {
//      Serial.println("Test 4");
//      Serial.print("Angle = ");
//      Serial.println(phi);
//      Serial.print("a = ");
//      Serial.println(a);
//      Serial.print("c = ");
//      Serial.println(c);
//      Serial.print("d = ");
//      Serial.println(d);
//      Serial.println(counter);
//      Serial.print("distance = ");
//      Serial.println(mySensors.getDistanceFront());
//      phi = imuSensor.getPhi();
//      myRobot.rotateLeft(100);
//    }
//
//  } else {
//    while (phi < 359)
//    {
//      Serial.println("Test 5");
//      Serial.print("Angle = ");
//      Serial.println(phi);
//      Serial.print("a = ");
//      Serial.println(a);
//      Serial.print("c = ");
//      Serial.println(c);
//      Serial.print("d = ");
//      Serial.println(d);
//      Serial.println(counter);
//      Serial.print("distance = ");
//      Serial.println(mySensors.getDistanceFront());
//      phi = imuSensor.getPhi();
//      myRobot.rotateLeft(100);
//    }
//  }
//  counter++;
//  Serial.print("counter =");
//  Serial.println(counter);
//  Serial.print("distance = ");
//  Serial.println(mySensors.getDistanceFront());
//}

//void Navigate::rotateLeft()
//{
//  int dist = mySensors.getDistanceFront();
//  Serial.println("test 6");
//  Serial.print("Angle: ");
//  Serial.println(imuSensor.getPhi());
//  Serial.print("distance = ");
//  Serial.println(dist);
//  if (counter != 4)
//  {
//    while (imuSensor.getPhi() < a)
//    {
//      Serial.print("Angle: ");
//      Serial.println(imuSensor.getPhi());
//      Serial.println(a);
//      Serial.println("test 7 rotate a!=0");
//      Serial.print("distance = ");
//      Serial.println(dist);
//      myRobot.rotateLeft(90);
//
//    }
//  } else {
//    while (imuSensor.getPhi() != a )
//    {
//      Serial.print("counter :");
//      Serial.println(counter);
//      Serial.print("a: ");
//      Serial.println(a);
//      Serial.print("Angle: ");
//      Serial.println(imuSensor.getPhi());
//      Serial.println("test 7 !=a");
//      Serial.print("distance = ");
//      Serial.println(dist);
//      myRobot.rotateLeft(90);
//    }
//
//  }
//  myRobot.stopp();
//  counter++;
//
//}
=======
void Navigate::moveFwd(int angle,int pwm)
{
 myRobot.align(angle);
 myRobot.forwards(angle,pwm); 
}
>>>>>>> 04a5fd011c453fbcf9c88cf6e135ead706ab2953
