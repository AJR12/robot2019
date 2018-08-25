#include "Arduino.h"
#include "Navigate.h"


Navigate::Navigate(robot robotic, DistanceClass robSensors) {

  myRobot = robotic;
  mySensors = robSensors;

}
void Navigate::moveRight()
{
  
  while(mySensors.getDistanceRight() > 85)
  {
    myRobot.right(100);
  }
}
void Navigate::moveLeft()
{
    while(mySensors.getDistanceLeft() > 85)
  {
    myRobot.left(100);
  }
}
void Navigate::moveFwd()
{
    while(mySensors.getDistanceFront() > 85)
  {
    myRobot.forwards(100);
  }
}
void Navigate::moveBck()
{
    while(mySensors.getDistanceBack() > 85)
  {
    myRobot.backwards(100);
  }
}
void Navigate::moveAll()
{
  moveFwd();
  moveLeft();  
  moveBck();
  moveRight();
}
