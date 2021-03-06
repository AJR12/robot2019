#include "motors_test.h"
#include "Arduino.h"

Motor::Motor(int enA, int in1, int in2) {
  _pwm = enA;
  _fwd = in1;
  _bac = in2;
  pinMode(_pwm, OUTPUT);
  pinMode(_fwd, OUTPUT);
  pinMode(_bac, OUTPUT);

}

void Motor::forward(int pwmSpeed) {
  digitalWrite(_fwd, HIGH);
  digitalWrite(_bac, LOW);
  analogWrite(_pwm, pwmSpeed);
}

void Motor::backward(int pwmSpeed) {
  digitalWrite(_fwd, LOW);
  digitalWrite(_bac, HIGH);
  analogWrite(_pwm, pwmSpeed);
}


void Motor::stp() {
  digitalWrite(_fwd, LOW);
  digitalWrite(_bac, LOW);
  analogWrite(_pwm, 0);
}

int Motor::test() {
  return _pwm;
}

