#include "Arduino.h"
#include "robot.h"
#include "Imu.h"

robot::robot() {}

robot::robot(Motor m1, Motor m2, Motor m3, Motor m4, int Max, Imu imuSensor1 ) {

  _M1 = m1;
  _M2 = m2;
  _M3 = m3;
  _M4 = m4;
  imuSensor = imuSensor1;

  if (Max >= 0 && Max <= 255) {
    maxSpeed = Max;
  } else {
    maxSpeed = 0;
  }


}
void robot::goStraightTo(int desire) {

  angle = imuSensor.getPhi();
  error = wrap(angle - desire, -180, 180);
  double diff = error * 5;
  double max_v = 100;
  if (diff > max_v)diff = max_v; else if (diff < -max_v)diff = -max_v;
  forwardAbdul( 150 - diff , 150 + diff);

}
void robot::goInCircle(double increase) {

  setPoint = wrap(setPoint + increase, 0, 360);

  angle = imuSensor.getPhi();

  error = wrap(angle - setPoint, -180, 180);

  double diff = error * 5;
  double max_v = 100;
  if (diff > max_v)diff = max_v; else if (diff < -max_v)diff = -max_v;
  forwardAbdul( 150 - diff , 150 + diff);
}
double robot::wrap(double val, double min, double max) {
  double range = max - min;
  if (val < min)
    val += range;
  else if (val > max)
    val -= range;
  return val;
}
void robot::forwardAbdul(int pwm1, int pwm2) {

  _M1.forward(pwm1);
  _M2.forward(pwm2);
  _M3.forward(pwm2);
  _M4.forward(pwm1);
}

void robot::forwards(int pwm) {
  _M1.forward(pwm);
  _M2.forward(pwm);
  _M3.forward(pwm);
  _M4.forward(pwm);
}

void robot::backwards(int pwm) {
  _M1.backward(pwm);
  _M2.backward(pwm);
  _M3.backward(pwm);
  _M4.backward(pwm);
}
void robot::right(int pwm) {
  _M1.backward(pwm);
  _M2.forward(pwm);
  _M3.backward(pwm);
  _M4.forward(pwm);
}
void robot::left(int pwm) {
  _M1.forward(pwm);
  _M2.backward(pwm);
  _M3.forward(pwm);
  _M4.backward(pwm);
}
void robot::rotateRight(int pwm) {
  _M1.backward(pwm);
  _M2.forward(pwm);
  _M3.forward(pwm);
  _M4.backward(pwm);
}
void robot::rotateLeft(int pwm) {
  _M1.forward(pwm);
  _M2.backward(pwm);
  _M3.backward(pwm);
  _M4.forward(pwm);
}
void robot::diagonalLeftUp(int pwm) {
  _M1.forward(pwm);
  _M3.forward(pwm);
}
void robot::diagonalRightUp(int pwm) {
  _M2.forward(pwm);
  _M4.forward(pwm);
}


void robot::stopp() {
  _M1.stopp();
  _M2.stopp();
  _M3.stopp();
  _M4.stopp();
}

