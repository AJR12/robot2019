#include "Arduino.h"
#include "robot.h"


robot::robot(){}

robot::robot(Motor m1, Motor m2, Motor m3, Motor m4, int Max) {

  _M1 = m1;
  _M2 = m2;
  _M3 = m3;
  _M4 = m4;
  if (Max >= 0 && Max <= 255) {
    maxSpeed = Max;
  } else {
    maxSpeed = 0;
  }
  
  
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
robot::moveInCircular1 (int pwm1, int pwm2) {

  if (pwm1 > 0 && pwm2 > 0) {
    _M1.forward(pwm1);
    _M2.forward(pwm2);
    _M3.forward(pwm1);
    _M4.forward(pwm2);

  } else if (pwm1 <= 0 && pwm2 >= 0) {

    pwm1 = -pwm1;
    _M1.backward(pwm1);
    _M2.forward(pwm2);
    _M3.backward(pwm1);
    _M4.forward(pwm2);

  } else if (pwm1 >= 0 && pwm2 <= 0) {
    pwm2 = -pwm2;
    _M1.forward(pwm1);
    _M2.backward(pwm2);
    _M3.forward(pwm1);
    _M4.backward(pwm2);

  } else if (pwm1 < 0 && pwm2 < 0) {
    pwm1 = -pwm1;
    pwm2 = -pwm2;
    _M1.backward(pwm1);
    _M2.backward(pwm2);
    _M3.backward(pwm1);
    _M4.backward(pwm2);

  } else {
    stopp();
  }

}
void robot::moveInCircular(int delay1) {

  int pwm11 = maxSpeed;
  int pwm22 = maxSpeed;

  for ( ; pwm11 > 50 ; pwm11 -= 2) {
    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }

  pwm11 = -pwm11;
  for ( ; pwm11 > -maxSpeed ; pwm11 -= 2) {

    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }

  for (; pwm22 > 50 ; pwm22 -= 2) {
    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }
  pwm22 = -pwm22;
  for (; pwm22 > -maxSpeed ; pwm22 -= 2) {
    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }

  for ( ; pwm11 < -50 ; pwm11 += 2) {
    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }
  pwm11 = -pwm11;
  for ( ; pwm11 < maxSpeed ; pwm11 += 2) {

    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }
  for (; pwm22 < -50 ; pwm22 += 2) {
    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }
  pwm22 = -pwm22;
  for (; pwm22 < maxSpeed ; pwm22 += 2) {
    moveInCircular1 (pwm11, pwm22);
    Serial.print(pwm11 );
    Serial.print(" : " );
    Serial.println(pwm22 );
    delay(delay1);
  }
  Serial.print(pwm11 );
  Serial.print(" : " );
  Serial.println(pwm22 );
}
void robot::stopp() {
  _M1.stopp();
  _M2.stopp();
  _M3.stopp();
  _M4.stopp();
}
