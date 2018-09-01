#include "Arduino.h"
#ifndef motor_h


class Motor
{
  public:
    Motor();
    Motor(int enA, int in1, int in2); //enA pwnPin, in1 forwardPin, in2 backwardPin
    void forward(int);
    void backward(int);
    void stopp();

  private:
  
    int pwmPin;
    int forwardd;
    int backwardd;
 

};

Motor::Motor(int pwm, int forwardPin, int backwardPin){
  pinMode(pwm,OUTPUT);
  pinMode(forwardPin,OUTPUT);
  pinMode(backwardPin,OUTPUT);
  pwmPin = pwm;
  forwardd = backwardPin;
  backwardd= forwardPin;  
}

void Motor::forward(int pwm){
  digitalWrite(forwardd,HIGH);
  digitalWrite(backwardd,LOW);  
  analogWrite(pwmPin,pwm);
}

void Motor::backward(int pwm){
  digitalWrite(forwardd,LOW);
  digitalWrite(backwardd,HIGH);
  analogWrite(pwmPin,pwm);
}


void Motor::stopp(){
  digitalWrite(backwardd,LOW);
  digitalWrite(forwardd,LOW);
  analogWrite(pwmPin,0);
}
#endif
