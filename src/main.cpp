#ifndef main_test
#define main_test 1

#include <Arduino.h>
#include "WiFi.h"
#include "u8g2lib.h"
#include "time.h"


#define uS_TO_m_FACTOR 60000000   // Conversion factor for micro seconds to minutes
#define TIME_TO_SLEEP  1        // Time ESP32 will go to sleep (in minutes)
#define CLK1306 15
#define DATA1306 4
#define RST1306 16

// the OLED used
// U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);
  // U8G2_ssd1306_i2c_128x64_noname_1 u8g2(U8G2_R0,/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);
// U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,CLK1306,DATA1306,RST1306);
// U8G2_SSD1306_128X64_NONAME_F_2ND_HW_I2C u8g2(U8G2_R0, RST1306);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, RST1306, CLK1306, DATA1306);
int num_loops = 0;
char printable_time[50];

const char* ntpServer = "200.160.7.186"; // "a.st1.ntp.br";
const long  gmtOffset_sec = -3 * 3600;
const int   daylightOffset_sec = 0;  // se estiver horário verão=3600;


void setup()
{
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  pinMode(25, OUTPUT);

  u8g2.begin();

    struct tm tm;
    tm.tm_year = 2018 - 1900;
    tm.tm_mon = 10;
    tm.tm_mday = 15;
    tm.tm_hour = 20;
    tm.tm_min = 50;
    tm.tm_sec = 0;
    time_t t = mktime(&tm);
    printf("Setting time: %s", asctime(&tm));
    struct timeval now = { .tv_sec = t };
    settimeofday(&now, NULL);
}


void printLocalTime(char* input_time)
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    strcpy(input_time,"failed");
    return;
  }else{
    // strftime(timeStringBuff, sizeof(timeStringBuff), "%A, %B %d %Y %H:%M:%S", &timeinfo);
    strftime(input_time, 50, "%H:%M:%S", &timeinfo);

  }

}

void loop()
{

          u8g2.clear();
      // u8g2.setFont(u8g2_font_inr33_3x6_r);

      // printLocalTime(printable_time);

      digitalWrite(25,HIGH);

        u8g2.firstPage();
        do {
          u8g2.setFont(u8g2_font_ncenB14_tr);
          u8g2.drawStr(0,20,"Hello World!");
        } while ( u8g2.nextPage() );
          digitalWrite(25,LOW);
      // u8x8.setFont(u8g2_font_chroma48medium8_r);
      // u8x8.drawString(0,0,printable_time);
      // printLocalTime();
      delay(1000);
}

#endif
