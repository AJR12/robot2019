#include "oled.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

// reset pin not used on 4-pin OLED module
Adafruit_SSD1306 display(-1);  // -1 = no reset pin

// 128 x 64 pixel display
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void Oled::start() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
}

void Oled::dispPhi(float phi) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Phi: ");
  display.setCursor(50, 0);
  display.print(phi);


  display.display();
  display.clearDisplay();

}
void Oled::dispAll(float phi, int disF, int disB, int disL, int disR) {
  //  Display Phi
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Phi: ");
  display.setCursor(50, 0);
  display.print(phi);

  //  Display disF
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.print("F:");
  display.setCursor(25, 22);
  display.setTextSize(1);
  display.print(disF);

  //  Display disB
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(60, 20);
  display.print("B:");
  display.setCursor(85, 22);
  display.setTextSize(1);
  display.print(disB);

  //  Display disL
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 40);
  display.print("L:");
  display.setCursor(25, 42);
  display.setTextSize(1);
  display.print(disL);

  //  Display disR
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(60, 40);
  display.print("R:");
  display.setCursor(85, 42);
  display.setTextSize(1);
  display.print(disR);



  display.display();
  display.clearDisplay();

}


