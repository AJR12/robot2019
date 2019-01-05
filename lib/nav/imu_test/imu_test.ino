#include "Arduino.h"
#include "imu.h"
Imu imu;

void setup(void)
{
  Serial.begin(9600);
  imu.start();
}

void loop(void)
{
  
float phi = imu.getPhi();
Serial.print("phi = %f");
Serial.println(phi);
}

/* For more axis use :

  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");

*/
