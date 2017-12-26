#include "DFRobot_HT1632C.h"
//#include "GravityRtc.h"
#include "Wire.h"
#include "DS1307.h"
#define DATA 10
#define CS 11
#define WR 9
//GravityRtc rtc;     //RTC Initialization
DFRobot_HT1632C ht1632c = DFRobot_HT1632C(DATA, WR,CS);
 #define updata_flag 0 //1 updata time,0 only show time
 //Modify the following data
 #define TIME_YR    17
 #define TIME_MTH   12
 #define TIME_DATE  20
 #define TIME_DOW   3
 #define TIME_HR    12
 #define TIME_MIN   12
 #define TIME_SEC   0
 char* str[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};//week 
 int rtc[7];
char Str[5];
 void showtime()     //
   {
    RTC.get(rtc,true);
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
    
    Serial.println( str[rtc[3]-1]); /********WEEK*****/  
    Serial.println("**********");        
    }  
   }
void setup() {
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
  ht1632c.setCursor(0,0);
  //Serial.begin(9600);
  /*rtc.setup();

  //rtc.initRtc(2017,9,20,3,9,38,0);  //Set Time: 2017/June/19th/Monday/12:07:0 am
  //Please comment it after you have set time successfully!!!!!!!
  // put your setup code here, to run once:*/
  if(updata_flag)
  { Serial.println(" OldTime:  ");
   showtime();
    RTC.stop();    
    
    RTC.set(DS1307_SEC,TIME_SEC); //---Update time----      
    RTC.set(DS1307_MIN,TIME_MIN);
    RTC.set(DS1307_HR,TIME_HR);
    RTC.set(DS1307_DOW,TIME_DOW);
    RTC.set(DS1307_DATE,TIME_DATE);
    RTC.set(DS1307_MTH,TIME_MTH);
    RTC.set(DS1307_YR,TIME_YR);    
    RTC.start();    
    Serial.println(" SetTime:  ");
    showtime();     
   }
}

void loop() {
  /*rtc.update();
  // put your main code here, to run repeatedly:
int i = rtc.hour/10;
switch(i){
  case 0:str[0] = '0';break;
  case 1:str[0] = '1';break;
  case 2:str[0] = '2';break;
  
  default:  break;
}
int j = rtc.hour%10;
switch(j){
  case 0:str[1] = '0';break;
  case 1:str[1] = '1';break;
  case 2:str[1] = '2';break;
  case 3:str[1] = '3';break;
  case 4:str[1] = '4';break;
  case 5:str[1] = '5';break;
  case 6:str[1] = '6';break;
  case 7:str[1] = '7';break;
  case 8:str[1] = '8';break;
  case 9:str[1] = '9';break;
  default:  break;
}
int k = rtc.second%10;
switch(k){
  case 0:str[2] = ' ';break;
  case 1:str[2] = ':';break;
  case 2:str[2] = ' ';break;
  case 3:str[2] = ':';break;
  case 4:str[2] = ' ';break;
  case 5:str[2] = ':';break;
  case 6:str[2] = ' ';break;
  case 7:str[2] = ':';break;
  case 8:str[2] = ' ';break;
  case 9:str[2] = ':';break;
  default:  break;
}
//str[2] = '-';
int x= rtc.minute/10;
switch(x){
  case 0:str[3] = '0';break;
  case 1:str[3] = '1';break;
  case 2:str[3] = '2';break;
  case 3:str[3] = '3';break;
  case 4:str[3] = '4';break;
  case 5:str[3] = '5';break;
  
  default:  break;
}
int y = rtc.minute%10;
switch(y){
  case 0:str[4] = '0';break;
  case 1:str[4] = '1';break;
  case 2:str[4] = '2';break;
  case 3:str[4] = '3';break;
  case 4:str[4] = '4';break;
  case 5:str[4] = '5';break;
  case 6:str[4] = '6';break;
  case 7:str[4] = '7';break;
  case 8:str[4] = '8';break;
  case 9:str[4] = '9';break;
  default:  break;
}
str[5] = ' ';
str[6] = ' ';
ht1632c.print(str);
*/
if(updata_flag==0)
     {showtime();    //Output data from serial port
     int i = rtc[2]/10;
switch(i){
  case 0:Str[0] = '0';break;
  case 1:Str[0] = '1';break;
  case 2:Str[0] = '2';break;
  
  default:  break;
}
int j = rtc[2]%10;
switch(j){
  case 0:Str[1] = '0';break;
  case 1:Str[1] = '1';break;
  case 2:Str[1] = '2';break;
  case 3:Str[1] = '3';break;
  case 4:Str[1] = '4';break;
  case 5:Str[1] = '5';break;
  case 6:Str[1] = '6';break;
  case 7:Str[1] = '7';break;
  case 8:Str[1] = '8';break;
  case 9:Str[1] = '9';break;
  default:  break;
}
int k = rtc[0]%10;
switch(k){
  case 0:Str[2] = ' ';break;
  case 1:Str[2] = ':';break;
  case 2:Str[2] = ' ';break;
  case 3:Str[2] = ':';break;
  case 4:Str[2] = ' ';break;
  case 5:Str[2] = ':';break;
  case 6:Str[2] = ' ';break;
  case 7:Str[2] = ':';break;
  case 8:Str[2] = ' ';break;
  case 9:Str[2] = ':';break;
  default:  break;
}
//str[2] = '-';
int x= rtc[1]/10;
switch(x){
  case 0:Str[3] = '0';break;
  case 1:Str[3] = '1';break;
  case 2:Str[3] = '2';break;
  case 3:Str[3] = '3';break;
  case 4:Str[3] = '4';break;
  case 5:Str[3] = '5';break;
  
  default:  break;
}
int y = rtc[1]%10;
switch(y){
  case 0:Str[4] = '0';break;
  case 1:Str[4] = '1';break;
  case 2:Str[4] = '2';break;
  case 3:Str[4] = '3';break;
  case 4:Str[4] = '4';break;
  case 5:Str[4] = '5';break;
  case 6:Str[4] = '6';break;
  case 7:Str[4] = '7';break;
  case 8:Str[4] = '8';break;
  case 9:Str[4] = '9';break;
  default:  break;
}
Str[5] = ' ';
Str[6] = ' ';
ht1632c.print(Str);}
    delay(1000);
}
