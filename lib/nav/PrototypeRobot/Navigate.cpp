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
  
  do
  {

    myRobot.forwards(100);


    if (imuSensor.getPhi() > a + 1)
    {     
      myRobot.stopp();
      myRobot.leftWheels(110);
      myRobot.rightWheels(90);


    }
    else if (imuSensor.getPhi() < a - 1 )
    {
      myRobot.stopp();
      myRobot.leftWheels(90);
      myRobot.rightWheels(110);

    }
  } while(mySensors.getDistanceFront() > 50);




    if ((counter % 4) == 1)
    {
      while ((int)imuSensor.getPhi() < 91)
      {
        myRobot.rotateLeft(80);
      }
      a = 90;
      counter++;
      myRobot.stopp();

    } else if ((counter % 4) == 2)
    {
      while ((int)imuSensor.getPhi() < 181)
      {
        myRobot.rotateLeft(80);
      }
      a=180;
      counter++;
      myRobot.stopp();

    }
    else if ((counter % 4) == 3)
    {
      a=270;
      while ((int)imuSensor.getPhi() < 271)
      {
        myRobot.rotateLeft(80);
      }
      counter++;
      myRobot.stopp();

    }
    else if ((counter % 4) == 0)
    {
      a=0;
      while ((((int)imuSensor.getPhi() < 360)||((int)imuSensor.getPhi()!=0))&&((int)imuSensor.getPhi() > 270))
      {
        myRobot.rotateLeft(80);
      }
      counter++;
      myRobot.stopp();

    } else
      return;



}
