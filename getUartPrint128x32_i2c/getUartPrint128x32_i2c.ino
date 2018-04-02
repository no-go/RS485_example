#include <Wire.h> // i2c
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"

#define OLED_RESET 4  // Pin 4 unused
Adafruit_SSD1306 display(OLED_RESET);

#define BUFFLEN     42
char buff[BUFFLEN] = "Please send something:"; // 22 chars
int  count         = 22;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    buff[count] = inChar;
    buff[count+1] = '\0';
    count++;
    if(count >= BUFFLEN) count = 0;
  }
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(buff);
  display.display();
}


