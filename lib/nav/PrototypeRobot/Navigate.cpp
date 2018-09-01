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

  //  switch (counter % 4) {
  //    case 1:
  //      a = 0;
  //      c = 359;
  //      d = 330;
  //      myRobot.forwards(100);
  //      moveTurn();
  //      rotateLeft();
  //      break;
  //    case 2:
  //      a = 90;
  //      c = 89;
  //      d = 60;
  //      myRobot.forwards(100);
  //      moveTurn();
  //      rotateLeft();
  //      break;
  //    case 3:
  //      a = 180;
  //      c = 179;
  //      d = 160;
  //      myRobot.forwards(100);
  //      moveTurn();
  //      rotateLeft();
  //      break;
  //    case 4:
  //      a = 270;
  //      c = 269;
  //      d = 250;
  //      myRobot.forwards(100);
  //      moveTurn();
  //      rotateLeft();
  //      break;
  //    default:
  //      break;
  //
  //  }
  while ( mySensors.getDistanceFront() > 40)
  {
    //    Serial.println("test 2");
    //    //phi = imuSensor.getPhi();
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
    //    Serial.println(dist);
    myRobot.forwards(100);


    if ((imuSensor.getPhi() > a + 1) && (imuSensor.getPhi() < a + 20))
    {
      //      Serial.println("test 3");
      //      Serial.println(counter);
      //      Serial.print("Angle: ");
      //      Serial.println(phi);
      myRobot.leftWheels(120);
      myRobot.rightWheels(90);

      //      Serial.print("distance = ");
      //      Serial.println(dist);
    }
    else if ((imuSensor.getPhi() < c) && (imuSensor.getPhi() > d))
    {
      //      Serial.println("test 4");
      //      Serial.println(counter);
      //      Serial.print("Angle: ");
      //      Serial.println(phi);
      myRobot.leftWheels(90);
      myRobot.rightWheels(120);

      //      Serial.print("distance = ");
      //      Serial.println(dist);
    }



  }
  if (counter == 1)
  {
    while ((int)imuSensor.getPhi() < 90)
    {
      myRobot.rotateLeft(80);
    }
    counter++;
    myRobot.stopp();

  } else if (counter == 2)
  {
    while ((int)imuSensor.getPhi() < 90)
    {
      myRobot.rotateLeft(80);
    }
        counter++;
    myRobot.stopp();

  }
  else if (counter == 3)
  {
    while ((int)imuSensor.getPhi() < 270)
    {
      myRobot.rotateLeft(80);
    }
        counter++;
    myRobot.stopp();

  }
  else
  {
    while ((int)imuSensor.getPhi() < 360)
    {
      myRobot.rotateLeft(80);
    }
        counter++;
    myRobot.stopp();

  }


}

void Navigate::moveTurn()
{


  //
  //  Serial.println("test 1");
  //  Serial.println(mySensors.getDistanceFront());
  //  int dist = mySensors.getDistanceFront();
  //  while ( mySensors.getDistanceFront() > 40)
  //  {
  ////    Serial.println("test 2");
  ////    //phi = imuSensor.getPhi();
  ////    Serial.print("Angle = ");
  ////    Serial.println(phi);
  ////    Serial.print("a = ");
  ////    Serial.println(a);
  ////    Serial.print("c = ");
  ////    Serial.println(c);
  ////    Serial.print("d = ");
  ////    Serial.println(d);
  ////    Serial.println(counter);
  ////    Serial.print("distance = ");
  ////    Serial.println(dist);
  //
  //
  //    if ((imuSensor.getPhi() > a + 1) && (imuSensor.getPhi() < a + 20))
  //    {
  ////      Serial.println("test 3");
  ////      Serial.println(counter);
  ////      Serial.print("Angle: ");
  ////      Serial.println(phi);
  //      myRobot.leftWheels(120);
  //      myRobot.rightWheels(90);
  //
  ////      Serial.print("distance = ");
  ////      Serial.println(dist);
  //    }
  //    else if ((imuSensor.getPhi() < c) && (imuSensor.getPhi() > d))
  //    {
  ////      Serial.println("test 4");
  ////      Serial.println(counter);
  ////      Serial.print("Angle: ");
  ////      Serial.println(phi);
  //      myRobot.leftWheels(90);
  //      myRobot.rightWheels(120);
  //
  ////      Serial.print("distance = ");
  ////      Serial.println(dist);
  //    }
  //
  //  }
  //  Serial.println("Test 5");
  //myRobot.stopp();
  //counter++;
  //  Serial.println(counter);
  //  Serial.print("distance = ");
  //  Serial.println(dist);


}

void Navigate::rotateLeft()
{

  Serial.println("test 6");
  Serial.print("Angle: ");
  Serial.println(imuSensor.getPhi());
  Serial.print("distance = ");
  Serial.println(mySensors.getDistanceFront());

  //  if (counter != 4)
  //  {
  //    while ((int)imuSensor.getPhi() < a)
  //    {
  ////      Serial.print("Angle: ");
  ////      Serial.println(imuSensor.getPhi());
  ////      Serial.println(a);
  ////      Serial.println("test 7 rotate a!=0");
  ////      Serial.print("distance = ");
  ////      Serial.println(dist);
  //      myRobot.rotateLeft(80);
  //
  //    }
  //  } else {
  //    while ((int)imuSensor.getPhi() != a )
  //    {
  ////      Serial.print("counter :");
  ////      Serial.println(counter);
  ////      Serial.print("a: ");
  ////      Serial.println(a);
  ////      Serial.print("Angle: ");
  ////      Serial.println(imuSensor.getPhi());
  ////      Serial.println("test 7 !=a");
  ////      Serial.print("distance = ");
  ////      Serial.println(dist);
  //      myRobot.rotateLeft(80);
  //    }
  //
  //  }
  myRobot.stopp();
  counter++;
}
