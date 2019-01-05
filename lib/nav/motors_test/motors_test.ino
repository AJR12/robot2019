#include "Arduino.h"
#include "motors_test.h"

Motor motor(11, 12, 13);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello");

}

void loop() {
  motor.forward(255);
  delay(2000);
  motor.backward(255);
  delay(2000);
  motor.stp();
  delay(2000);
  //pinMode(12, OUTPUT);
  //digitalWrite(12, HIGH);


}
