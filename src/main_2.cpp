/*
#ifndef main_test
#define main_test 1
#include <Arduino.h>
#include "SSD1306.h"


#define DURATION 200
#define OLED_RST 16
#define OLED_SDA 4
#define OLED_SCL 25
SSD1306Wire  display(0x3c, OLED_SDA, OLED_SCL);
void setup() {
  // put your setup code here, to run once:


    pinMode(OLED_RST,OUTPUT);
  digitalWrite(OLED_RST, LOW); // set GPIOOLED_RST low to reset OLED
  delay(50);
  digitalWrite(OLED_RST, HIGH); // while OLED is running, must set GPIOOLED_RST to high

  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println("ESP32 bootup");


  // Initialising the UI will init the display too.
  display.init();

  //display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(10, 128, String(millis()));
  display.display();

  Serial.println("ESP32 loop");
  //if (millis() - timeSinceLastModeSwitch > DURATION) {
  //  timeSinceLastModeSwitch = millis();
  //}
  //counter++;
  delay(500);
  // put your main code here, to run repeatedly:

}
#define
*/
