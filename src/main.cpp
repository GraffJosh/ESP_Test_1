#ifndef main_test
#define main_test 1

#include "WiFi.h"
#include "U8x8lib.h"

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

int num_loops = 0;
char currentSSID[15];

void setup()
{
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  pinMode(25, OUTPUT);

  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
}


static void doSomeWork()
{
  int n = WiFi.scanNetworks();

  if (n == 0) {
    u8x8.drawString(0, 0, "Searching networks.");
  } else {
    u8x8.drawString(0, 0, "Networks found: ");
    for (int i = 0; i < n; ++i) {
      // Print SSID for each network found
      char currentSSID[64];
      WiFi.SSID(i).toCharArray(currentSSID, 64);
      u8x8.drawString(0, i + 1, currentSSID);
    }
  }

  // Wait a bit before scanning again
  delay(5000);
}


void loop()
{

  if (num_loops%5==0) {

          u8x8.clear();
      u8x8.setFont(u8x8_font_inr33_3x6_r);
      u8x8.drawString(0, 2, "06:53");
      delay(1000);
      u8x8.clear();
  }
  if (num_loops % 5 == 0) {

      u8x8.clear();

      u8x8.setFont(u8x8_font_chroma48medium8_r);
      u8x8.drawString(0, 0, "Searching.");

      digitalWrite(25,HIGH);
        int n = WiFi.scanNetworks();
        digitalWrite(25,LOW);
      WiFi.SSID(1).toCharArray(currentSSID, 15);
      u8x8.clear();
  }

  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0, 0, "Networks found: ");

  u8x8.drawString(0, 2, currentSSID);

  Serial.println("ESP32 loop");
  delay(500);
  num_loops++;
  if(num_loops == 500)
  {
    num_loops = 0;
  }
}

#endif
