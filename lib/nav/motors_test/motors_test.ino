#include "Arduino.h"
#include "motors_test.h"

Motor motor(44, 22, 24);
Motor motor2(45, 26, 28);
Motor motor3(46, 48, 50);
Motor motor4(5, 52, 51);


#define ENCODEROUTPUT 1200


int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;

int rpm1 = 0;
int rpm2 = 0;
int rpm3 = 0;
int rpm4 = 0;

volatile long encoderValue1 = 0;
volatile long encoderValue2 = 0;
volatile long encoderValue3 = 0;
volatile long encoderValue4 = 0;

void count1(void);
void count2(void);
void count3(void);
void count4(void);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(ENCODEROUTPUT);

  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), count1, RISING);

  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), count2, RISING);

  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), count1, RISING);

  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), count2, RISING);

  encoderValue1 = 0;
  encoderValue2 = 0;
  encoderValue3 = 0;
  encoderValue4 = 0;

}

void loop() {
  motor.forward(255);
  motor2.forward(255);
  motor3.forward(255);
  motor4.forward(255);

  //  currentMillis = millis();
  //
  //  if (currentMillis - previousMillis > interval) {
  //    previousMillis = millis();
  //    rpm1 = (encoderValue1 * 60 / ENCODEROUTPUT);
  //    rpm2 = (encoderValue2 * 60 / ENCODEROUTPUT);
  //    Serial.print("RPM_1 = "); Serial.println(rpm1);
  //    Serial.print("RPM_2 = "); Serial.println(rpm2);
  //    Serial.print("Encoder Value1="); Serial.println(encoderValue1);
  //    Serial.print("Encoder Value2="); Serial.println(encoderValue2);
  //    encoderValue1 = 0;
  //    encoderValue2 = 0;
  //  }
  //





}

void count1()

{

  encoderValue1++;

}

void count2() {
  encoderValue2++;
}










//  motor.forward(255);
//  delay(2000);
//  motor.backward(255);
//  delay(2000);
//  motor.stp();
//  delay(2000);


