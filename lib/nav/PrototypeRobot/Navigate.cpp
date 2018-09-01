#include "Arduino.h"
#include "Navigate.h"
#include "Imu.h"


Navigate::Navigate(robot robotic, DistanceClass robSensors, Imu phiSensor) {

  myRobot = robotic;
  mySensors = robSensors;
  imuSensor = phiSensor;

}

void Navigate::moveFwd()
{
  
  Serial.print("counter =");
  Serial.println(counter % 4);

  switch (counter % 4) {
    case 1:
      a = 0;
      c = 359;
      d = 330;
      myRobot.forwards(100);
      moveTurn();
      rotateLeft();

      break;
    case 2:
      a = 90;
      c = 89;
      d = 60;
      myRobot.forwards(100);
      moveTurn();
      rotateLeft();
      break;
    case 3:
      a = 180;
      c = 179;
      d = 160;
      myRobot.forwards(100);
      moveTurn();
      rotateLeft();
      break;
    case 4:
      a = 270;
      c = 269;
      d = 250;
      myRobot.forwards(100);
      moveTurn();
      rotateLeft();
      break;
    default:
      break;

  }
  
}

void Navigate::moveTurn()
{
  
  

  Serial.println("test 1");
  Serial.println(mySensors.getDistanceFront());
  int dist = mySensors.getDistanceFront();
  while ( mySensors.getDistanceFront() > 55)
  {
    Serial.println("test 2");
    //phi = imuSensor.getPhi();   
    Serial.print("Angle = ");
    Serial.println(phi);
    Serial.print("a = ");
    Serial.println(a);
    Serial.print("c = ");
    Serial.println(c);
    Serial.print("d = ");
    Serial.println(d);
    Serial.println(counter);
    Serial.print("distance = ");
    Serial.println(dist);


    while ((imuSensor.getPhi() > a + 1) && (imuSensor.getPhi() < a + 20))
    {
      Serial.println("test 3");
      Serial.println(counter);
      Serial.print("Angle: ");
      Serial.println(phi);
      myRobot.leftWheels(130);
      myRobot.rightWheels(90);
      
      Serial.print("distance = ");
      Serial.println(dist);
    }
    while ((imuSensor.getPhi() < c) && (imuSensor.getPhi() > d))
    {
      Serial.println("test 4");
      Serial.println(counter);
      Serial.print("Angle: ");
      Serial.println(phi);
      myRobot.leftWheels(90);
      myRobot.rightWheels(130);
      
      Serial.print("distance = ");
      Serial.println(dist);
    }
    
  }
  Serial.println("Test 5");
  //myRobot.stopp();
  //counter++;
  Serial.println(counter);
  Serial.print("distance = ");
  Serial.println(dist);
  

}

void Navigate::rotateLeft()
{
  int dist = mySensors.getDistanceFront();
  Serial.println("test 6");
  Serial.print("Angle: ");
  Serial.println(imuSensor.getPhi());
  Serial.print("distance = ");
  Serial.println(dist);
  if (counter != 4)
  {
    while (imuSensor.getPhi() < a)
    {
      Serial.print("Angle: ");
      Serial.println(imuSensor.getPhi());
      Serial.println(a);
      Serial.println("test 7 rotate a!=0");
      Serial.print("distance = ");
      Serial.println(dist);
      myRobot.rotateLeft(90);
      
    }
  } else {
    while (imuSensor.getPhi() != a )
    {
      Serial.print("counter :");
      Serial.println(counter);
      Serial.print("a: ");
      Serial.println(a);
      Serial.print("Angle: ");
      Serial.println(imuSensor.getPhi());
      Serial.println("test 7 !=a");
      Serial.print("distance = ");
      Serial.println(dist);
      myRobot.rotateLeft(90);
    }

  }
  myRobot.stopp();
  counter++;

}
