#include "Arduino.h"
#include "robot.h"
#include "Imu.h"

robot::robot() {}

robot::robot(Motor m1, Motor m2, Motor m3, Motor m4, int Max ) {

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
void robot::initialize(){
  imuSensor.bno.setExtCrystalUse(true);
  imuSensor.bno.begin();
}



void robot::backwards(int pwm) {
  _M1.backward(pwm);
  _M2.backward(pwm);
  _M3.backward(pwm);
  _M4.backward(pwm);
}

void robot::forwardAbdul(int pwm1,int pwm2) {
  
  _M1.forward(pwm1);
  _M2.forward(pwm2);
  _M3.forward(pwm2);
  _M4.forward(pwm1);
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
void robot::rightWheels(int pwm1)
{
  _M1.forward(pwm1);
  _M4.forward(pwm1);
}
void robot::leftWheels(int pwm1)
{
  _M2.forward(pwm1);
  _M3.forward(pwm1);
}


void robot::moveInCircle(double increase){
  desireAngle = wrap(desireAngle + increase, 0, 360);
  updateError();
  double diff = error * 5;
  double max_v = 100;
  if (diff > max_v)diff = max_v; else if (diff < -max_v)diff = -max_v;
  forwardAbdul( 150 - diff , 150 + diff);
}
void robot::updateError(){
  angle = imuSensor.getPhi();
  error = wrap(angle-desireAngle, -180, 180);
}
double robot::wrap(double val, double min, double max){
  double range = max - min;
  if (val < min)
    val += range;
  else if (val > max)
    val -= range;
  return val;
}
//void robot::align(int a) {
//  float phi = imuSensor.getPhi();
//  Serial.print("a =");
//  Serial.println(a);
//  Serial.print("phi =");
//  Serial.println(phi);
//
//  if (a <= 180) { //a <= 180
//
//    Serial.println("test 1 a <= 180");
//
//    if ((phi <= a + 180) && (phi > a)) {    //phi is b/t a and (a+180)
//
//      Serial.println("test 2 phi is b/t a and (a+180)");
//      Serial.print("abs(phi - a)=");
//      Serial.println(abs(phi - a));
//      phi = imuSensor.getPhi();
//      while (phi - a < .1) {
//        Serial.println("test 3 rotateRight to correct");
//        Serial.print("phi =");
//        Serial.println(phi);
//        rotateRight(100);
//        phi = imuSensor.getPhi();
//
//      }
//      stopp();
//      return;
//      Serial.println("test 4 exited rotateRight loop");
//      Serial.print("phi =");
//      Serial.println(phi);
//    } else if ((phi < a) || (phi > a + 180)) {   //phi is < a but > 180
//      Serial.println("test 2 phi is b/t a and (a+180)");
//      Serial.print("phi =");
//      Serial.println(phi);
//      while (phi - a < .1) {
//        Serial.println("test 3 rotating left");
//        Serial.print("phi =");
//        Serial.println(phi);
//        rotateLeft(100);
//        phi = imuSensor.getPhi();
//
//      }
//      Serial.print("phi - a =");
//        Serial.println(phi -a);
//      stopp();
//      return;
//    }
//  } else {    //a > 180
//    if ((phi > a - 180) && (phi < a)) {   //phi < a but > (a-180)
//      while (phi - a < .1) {
//        rotateLeft(100);
//        phi = imuSensor.getPhi();
//
//      }
//      stopp();
//      return;
//    }
//    if ((phi > a) || (phi <= a - 180)) { //phi > a but < (a-180)
//      while (phi - a > .1) {
//        rotateRight(100);
//        phi = imuSensor.getPhi();
//
//      }
//      stopp();
//      return;
//    }
//  }
//  stopp();
//  Serial.println("test 5 stopped. exit align");
//}
///////////////////////////////
//void robot::forwards(int pwm, int a) {
//
//
//  float phi = imuSensor.getPhi();
//  int pwm_up = pwm + 10;
//  int pwm_dwn = pwm - 10;
//
//  Serial.println("test 0 enter forwards function");
//  if (abs(phi - a) > 1) {
//    align(a);
//  }
//
//  Serial.println("test 6 reentered forwards function");
//  Serial.print("a = ");
//  Serial.println(a);
//  Serial.print("phi = ");
//  Serial.println(phi);
//
//  _M1.forward(pwm);
//  _M2.forward(pwm);
//  _M3.forward(pwm);
//  _M4.forward(pwm);
//
//  if (a != 0) {
//
//    while ((phi > a + .2) && (phi < a + 20))
//    {
//      phi = imuSensor.getPhi();
//      _M2.forward(pwm_up);
//      _M3.forward(pwm_up);
//      _M1.forward(pwm_dwn);
//      _M4.forward(pwm_dwn);
//
//      Serial.println("test 5");
//      Serial.print("pwm_up");
//      Serial.println(pwm_up);
//      Serial.print("pwm_dwn");
//      Serial.println(pwm_dwn);
//      Serial.print("phi =");
//      Serial.println(phi);
//
//    }
//    while ((phi < a - .2) && (phi > a - 20))
//    {
//      phi = imuSensor.getPhi();
//      _M2.forward(pwm_dwn);
//      _M3.forward(pwm_dwn);
//      _M1.forward(pwm_up);
//      _M4.forward(pwm_up);
//
//      Serial.println("test 5");
//      Serial.print("pwm_up");
//      Serial.println(pwm_up);
//      Serial.print("pwm_dwn");
//      Serial.println(pwm_dwn);
//      Serial.print("phi =");
//      Serial.println(phi);
//    }
//  } else {
//    while ((phi > a + .2) && (phi < a + 20))
//    {
//      phi = imuSensor.getPhi();
//      _M2.forward(pwm_up);
//      _M3.forward(pwm_up);
//      _M1.forward(pwm_dwn);
//      _M4.forward(pwm_dwn);
//
//      Serial.println("test 5 a = 0; curving left (1 < phi < 20)");
//      Serial.print("Left motors (M2/M3) pwm =");
//      Serial.println(pwm_up);
//      Serial.print("Right motors (M1/M4) pwm =");
//      Serial.println(pwm_dwn);
//      Serial.print("phi =");
//      Serial.println(phi);
//    }
//    while ((phi < 359.8) && (phi > 340))
//    {
//      phi = imuSensor.getPhi();
//      _M2.forward(pwm_dwn);
//      _M3.forward(pwm_dwn);
//      _M1.forward(pwm_up);
//      _M4.forward(pwm_up);
//
//      Serial.println("test 6 a = 0; curving right (340 < phi < 359)");
//      Serial.print("Left motors (M2/M3) pwm =");
//      Serial.println(pwm_dwn);
//      Serial.print("Right motors (M1/M4) pwm =");
//      Serial.println(pwm_up);
//      Serial.print("phi =");
//      Serial.println(phi);
//    }
//  }
//}



//robot::moveInCircular1 (int pwm1, int pwm2) {
//
//  if (pwm1 > 0 && pwm2 > 0) {
//    _M1.forward(pwm1);
//    _M2.forward(pwm2);
//    _M3.forward(pwm1);
//    _M4.forward(pwm2);
//
//  } else if (pwm1 <= 0 && pwm2 >= 0) {
//
//    pwm1 = -pwm1;
//    _M1.backward(pwm1);
//    _M2.forward(pwm2);
//    _M3.backward(pwm1);
//    _M4.forward(pwm2);
//
//  } else if (pwm1 >= 0 && pwm2 <= 0) {
//    pwm2 = -pwm2;
//    _M1.forward(pwm1);
//    _M2.backward(pwm2);
//    _M3.forward(pwm1);
//    _M4.backward(pwm2);
//
//  } else if (pwm1 < 0 && pwm2 < 0) {
//    pwm1 = -pwm1;
//    pwm2 = -pwm2;
//    _M1.backward(pwm1);
//    _M2.backward(pwm2);
//    _M3.backward(pwm1);
//    _M4.backward(pwm2);
//
//  } else {
//    stopp();
//  }
//
//}
//void robot::moveInCircular(int delay1) {
//
//  int pwm11 = maxSpeed;
//  int pwm22 = maxSpeed;
//
//  for ( ; pwm11 > 50 ; pwm11 -= 2) {
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//
//  pwm11 = -pwm11;
//  for ( ; pwm11 > -maxSpeed ; pwm11 -= 2) {
//
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//
//  for (; pwm22 > 50 ; pwm22 -= 2) {
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//  pwm22 = -pwm22;
//  for (; pwm22 > -maxSpeed ; pwm22 -= 2) {
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//
//  for ( ; pwm11 < -50 ; pwm11 += 2) {
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//  pwm11 = -pwm11;
//  for ( ; pwm11 < maxSpeed ; pwm11 += 2) {
//
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//  for (; pwm22 < -50 ; pwm22 += 2) {
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//  pwm22 = -pwm22;
//  for (; pwm22 < maxSpeed ; pwm22 += 2) {
//    moveInCircular1 (pwm11, pwm22);
//    Serial.print(pwm11 );
//    Serial.print(" : " );
//    Serial.println(pwm22 );
//    delay(delay1);
//  }
//  Serial.print(pwm11 );
//  Serial.print(" : " );
//  Serial.println(pwm22 );
//}

