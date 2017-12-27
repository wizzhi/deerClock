#include "DFRobot_HT1632C.h"
//#include "GravityRtc.h"
#include "Wire.h"
#include "DS1307.h"
#define DATA 10
#define CS 11
#define WR 9
//GravityRtc rtc;     //RTC Initialization
DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR, CS);
#define updata_flag 0 //1 updata time,0 only show time
//Modify the following data
#define TIME_YR    17
#define TIME_MTH   12
#define TIME_DATE  27
#define TIME_DOW   3
#define TIME_HR    10
#define TIME_MIN   42
#define TIME_SEC   0
char* str[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; //week
int rtc[7];
char Str[5];
void showtime()
{
  RTC.get(rtc, true);
  {
    Serial.print( rtc[6]);   /*YEAR MONTH DATE*/
    Serial.print("-");
    Serial.print( rtc[5]);
    Serial.print("-");
    Serial.println( rtc[4]);

    Serial.print( rtc[2]); /*HOUR  MIN SEC */
    Serial.print(":");
    Serial.print( rtc[1]);
    Serial.print(":");
    Serial.println( rtc[0]);

    Serial.println( str[rtc[3] - 1]); /********WEEK*****/
    Serial.println("**********");
  }
}
void setup() {
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
  ht1632c.setCursor(0, 0);

  if (updata_flag)
  {
    Serial.println(" OldTime:  ");
    showtime();
    RTC.stop();

    RTC.set(DS1307_SEC, TIME_SEC); //---Update time----
    RTC.set(DS1307_MIN, TIME_MIN);
    RTC.set(DS1307_HR, TIME_HR);
    RTC.set(DS1307_DOW, TIME_DOW);
    RTC.set(DS1307_DATE, TIME_DATE);
    RTC.set(DS1307_MTH, TIME_MTH);
    RTC.set(DS1307_YR, TIME_YR);
    RTC.start();
    Serial.println(" SetTime:  ");
    showtime();
  }
}

void loop() {
  if (updata_flag == 0)
  {
    showtime();    //Output data from serial port

    int n = 0;
    Str[n++] = rtc[4] / 10 + '0';
    Str[n++] = rtc[4] % 10 + '0';
    Str[n++] = ' ';
    Str[n++] = rtc[2] / 10 + '0';
    Str[n++] = rtc[2] % 10 + '0';
    Str[n++] = ':';
    Str[n++] = rtc[1] / 10 + '0';
    Str[n++] = rtc[1] % 10 + '0';
    Str[n++] = ' ';
    Str[n++] = 'P';
    Str[n++] = 'h';
    Str[n++] = 'i';
    Str[n++] = 'l';
    Str[n++] = 'o';
    Str[n++] = ' ';
    Str[n++] = ' ';
    Str[n++] = ':';
    Str[n++] = ' ';
    Str[n++] = ')';
    ht1632c.print(Str, 100);
  }
}
