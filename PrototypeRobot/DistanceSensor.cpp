#include "Arduino.h"
#include "DistanceSensor.h"


DistanceSensor::DistanceSensor() {}

DistanceSensor::DistanceSensor(int trig, int echo) {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  trigPin = trig;
  echoPin = echo;
}

int DistanceSensor::getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  //Serial.print(distance);
  //Serial.println(" cm"); 
  delay(200);
  //pulseIn(echoPin, HIGH);

  return distance;

}
