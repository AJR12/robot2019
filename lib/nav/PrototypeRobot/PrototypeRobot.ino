#include "Arduino.h"
#include <Wire.h>
#include "laser_ds.h"
#include "imu.h"
#include "oled.h"
#include "robot.h"
#include "Navigate.h"


// Encoder definitions
#define ENCODER_1 19
#define ENCODER_2 18
#define ENCODER_3 3
#define ENCODER_4 2
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

Lasers lasers(13, 12, 11, 10); // (F, B, L, R)
Imu imu;
Oled oled;

Motor motor1(5, 52, 51);
Motor motor2(44, 22, 24);
Motor motor3(45, 48, 50);
Motor motor4(46, 26, 28);

void receiveEvent(int);
void count1();
void count2();
void count3();
void count4();

void forwards(int pwm);
void backwards(int pwm);
void right(int pwm);
void left(int pwm);
void rotateRight(int pwm);
void rotateLeft(int pwm);
void diagonalLeftUp(int pwm);
void diagonalRightUp(int pwm);
void stp();

void setup()
{
        //Initializing Arduino-Odroid Communication
        //through i2c address 8
        Wire.begin(9);
        Wire.onReceive(receiveEvent); //register event
        Serial.begin(9600);

//        //  Init Lasers dist sensors
//        Serial.println("HELLO!!!");
//        lasers.setAddy();
//        lasers.i2cScan();
//
//        //  Init IMU
//        imu.start();
//
//        //Init Oled
//        oled.start();
//
//        // Init Encoders
//        pinMode(ENCODER_1, INPUT);
//        pinMode(ENCODER_2, INPUT);
//        pinMode(ENCODER_3, INPUT);
//        pinMode(ENCODER_4, INPUT);
//        attachInterrupt(digitalPinToInterrupt(ENCODER_1), count1, RISING);
//        attachInterrupt(digitalPinToInterrupt(ENCODER_2), count2, RISING);
//        attachInterrupt(digitalPinToInterrupt(ENCODER_3), count3, RISING);
//        attachInterrupt(digitalPinToInterrupt(ENCODER_4), count4, RISING);

}

void loop()
{

        int disF = lasers.sensF();
        int disB = lasers.sensB();
        int disL = lasers.sensL();
        int disR = lasers.sensR();

        Serial.print("disF = ");
        Serial.println(disF);
        Serial.print("disB = ");
        Serial.println(disB);
        Serial.print("disL = ");
        Serial.println(disL);
        Serial.print("disR = ");
        Serial.println(disR);
        Serial.println("\n\n");

        float phi = imu.getPhi();
        Serial.print("phi = ");
        Serial.println(phi);

        delay(500);

        oled.dispAll(phi, disF, disB, disL, disR);
        //Wire.onReceive(receiveEvent);
        //rpm();
        delay(100);

}

void rpm()
{
        currentMillis = millis();
        if (currentMillis - previousMillis > interval)
        {
                previousMillis = millis();
                rpm1 = (encoderValue1 * 60 / ENCODEROUTPUT);
                rpm2 = (encoderValue2 * 60 / ENCODEROUTPUT);
                rpm3 = (encoderValue3 * 60 / ENCODEROUTPUT);
                rpm4 = (encoderValue4 * 60 / ENCODEROUTPUT);
                Serial.print("RPM_1 = "); Serial.println(rpm1);
                Serial.print("RPM_2 = "); Serial.println(rpm2);
                Serial.print("RPM_3 = "); Serial.println(rpm3);
                Serial.print("RPM_4 = "); Serial.println(rpm4);
                Serial.print("Encoder Value1 = "); Serial.println(encoderValue1);
                Serial.print("Encoder Value2 = "); Serial.println(encoderValue2);
                Serial.print("Encoder Value3 = "); Serial.println(encoderValue3);
                Serial.print("Encoder Value4 = "); Serial.println(encoderValue4);
                encoderValue1 = 0;
                encoderValue2 = 0;
                encoderValue3 = 0;
                encoderValue4 = 0;
        }

}
void count1()
{
        encoderValue1++;
}
void count2()
{
        encoderValue2++;
}
void count3()
{
        encoderValue3++;
}
void count4()
{
        encoderValue4++;
}

/*
   function that executes whenever data is received from master
   this function is registered as an event, see setup()
 */
void receiveEvent(int howMany)
{
        while (1 < Wire.available()) // loop through all but the last
        {
                char c = Wire.read(); // receive byte as a character
                Serial.print(c); // print the character
        }
        int x = Wire.read(); // receive byte as an integer
        Serial.println(x);
        receiveCommand(x);   // print the integer
}

void receiveCommand(int oComm)
{
        switch (oComm)
        {
        case 1:
                forwards(255);
                break;
        case 2:
                backwards(255);
                break;
        case 3:
                right(255);
                break;
        case 4:
                left(255);
                break;
        case 5:
                stp();
                break;
        default:
                rotateRight(100);
                break;
        }
}

void forwards(int pwm)
{
        motor1.forward(pwm);
        motor2.forward(pwm);
        motor3.forward(pwm);
        motor4.forward(pwm);
}

void backwards(int pwm)
{
        motor1.backward(pwm);
        motor2.backward(pwm);
        motor3.backward(pwm);
        motor4.backward(pwm);
}

void right(int pwm)
{
        motor1.backward(pwm);
        motor2.forward(pwm);
        motor3.backward(pwm);
        motor4.forward(pwm);
}

void left(int pwm)
{
        motor1.forward(pwm);
        motor2.backward(pwm);
        motor3.forward(pwm);
        motor4.backward(pwm);
}

void rotateRight(int pwm)
{
        motor1.backward(pwm);
        motor2.forward(pwm);
        motor3.forward(pwm);
        motor4.backward(pwm);
}

void rotateLeft(int pwm)
{
        motor1.forward(pwm);
        motor2.backward(pwm);
        motor3.backward(pwm);
        motor4.forward(pwm);
}

void diagonalLeftUp(int pwm)
{
        motor1.forward(pwm);
        motor3.forward(pwm);
}

void diagonalRightUp(int pwm)
{
        motor2.forward(pwm);
        motor4.forward(pwm);
}

void stp() {
        motor1.stp();
        motor2.stp();
        motor3.stp();
        motor4.stp();
}

//myRobot.align(45);
//}


//  for (int i = 0; i < 100; i++) {
//
//    switch (i % 4) {
//      case 0:
//        myRobot.align(45);
//        delay(1000);
//        break;
//      case 1:
//        myRobot.align(135);
//        delay(1000);
//        break;
//      case 2:
//        myRobot.align(225);
//        delay(1000);
//        break;
//      case 3:
//        Serial.println("Entering case 3 in Main");
//        myRobot.align(315);
//        Serial.println("Left case 3 in Main");
//        delay(1000);
//
//        break;
//      default:
//        myRobot.stopp();
//    }
//  }
//}





//  myRobot.align(180);

//  float phi = imuSensor.getPhi();
//  float distance = distanceSensor.getDistance();
//  Serial.print("phi");
//  Serial.println(imuSensor.getPhi());
//  Serial.print("distance=");
//  Serial.println(distance);

//  display.clearDisplay();
//  display.setTextSize(2);
//  display.setTextColor(WHITE);
//  display.setCursor(0,0);
//  display.print("Hello John");
//  display.setCursor(0,20);
//  display.print(imuSensor.getPhi());
//  display.setCursor(0,40);
//  display.print(distanceSensor.getDistance());
//  display.display();

//  myRobot.align(0);
//  Serial.print("level =");
//  Serial.println(1);
//  delay(2000);
//
//  myRobot.align(90);
//  Serial.print("level =");
//  Serial.println(2);
//  delay(2000);
//
//  myRobot.align(180);
//  Serial.print("level =");
//  Serial.println(3);
//  delay(2000);
//
//  myRobot.align(270);
//  Serial.print("level =");
//  Serial.println(4);
//  delay(2000);
//
//  myRobot.align(0);
//  Serial.print("level =");
//  Serial.println(5);
//  delay(2000);
//
//  myRobot.align(270);
//  Serial.print("level =");
//  Serial.println(6);
//  delay(2000);
//
//  myRobot.align(180);
//  Serial.print("level =");
//  Serial.println(7);
//  delay(2000);
//
//  myRobot.align(90);
//  Serial.print("level =");
//  Serial.println(8);
//  delay(2000);
//
//  myRobot.align(0);
//  Serial.print("level =");
//  Serial.println(9);
//  delay(2000);


//myNavigate.moveAll();
//delay(2000);

//sensors.printAll();


//  float phi = imuSensor.getPhi();
// myNavigate.moveSquare();
//  //myRobot.forwards(200);

//  display.clearDisplay();
//  display.setTextSize(2);
//  display.setTextColor(WHITE);
//  display.setCursor(0, 0);
//
//  display.println("test");
//  display.display();
//  display.setCursor(0, 20);
//  display.print(sensors.getDistanceFront());
//  display.setCursor(0, 40);
//  //display.print(x);

//  //delay(100);
//  display.clearDisplay();

// Serial.println(phi);
