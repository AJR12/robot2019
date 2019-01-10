#include "Arduino.h"
#include <Wire.h>
#include "imu.h"
Imu imu;


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

void setup() {
  Serial.begin(9600);
  imu.start();

  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

}

void loop() {
  float phi = imu.getPhi();
  Serial.print("phi = ");
  Serial.println(phi);

  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Phi: ");
  display.setCursor(50, 0);
  display.print(phi);

  
  display.display();
  display.clearDisplay();


}

