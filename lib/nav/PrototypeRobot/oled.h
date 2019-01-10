#ifndef OLED_h
#define OLED_h

class Oled {

  public:
    //      Constructor


    //  Methods
    void start();
    void dispPhi(float phi);
    void dispAll(float phi, int disF, int disB, int disL, int disR);

};

#endif
