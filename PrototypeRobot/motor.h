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
#endif
