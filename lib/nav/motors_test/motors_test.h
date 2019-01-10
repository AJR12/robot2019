#ifndef MOT_h
#define MOT_h

class Motor {

  public:
    //  Constructor
    Motor(int enA, int in1, int in2);

    //  Methods
    void start();
    void forward(int pwmSpeed);
    void backward(int pwmSpeed);
    void stp();
    int test();

  private:

    int _pwm;
    int _fwd;
    int _bac;


};

#endif
