#include <Wire.h>
#include <VL53L1X.h>

VL53L1X sensor;
VL53L1X sensor2;

void setup()
{
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(13, LOW);  
  digitalWrite(12, LOW);

  delay(500);
  Wire.begin();

  Serial.begin (115200);
  Serial.println("HELLO!!!");

  pinMode(12, INPUT);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)22);
  Serial.println("02");

  pinMode(13, INPUT);
  delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)43);
  Serial.println("04");

  Serial.println("addresses set");

Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;


  for (byte i = 1; i < 120; i++)
  {

    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1); 
    }
  }
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
  
  sensor.setTimeout(500);
  sensor2.setTimeout(500);

  sensor.startContinuous(50);
  sensor2.startContinuous(50);

}

void loop()
{
  Serial.print(sensor.readRangeContinuousMillimeters());
  Serial.print(',');
  Serial.print(sensor2.readRangeContinuousMillimeters());
  Serial.println();
}

