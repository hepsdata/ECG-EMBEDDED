/***************************************************************
* ECG Wireless Transmission System - Sender Code
*
* This code is adapted from the "2Ch_PSL_Serial.ino" file contained
* within the "아두이노 소스.zip" archive, which was provided by Physio Lab.
*
* Original code can be found in the shared folder at:
* [Physio Lab Shared Code](https://mybox.naver.com/share/list?shareKey=qwT2ayhcpdvQ5wsZ12FuLiQF-HgwWd8uWTQ1AJ6EfsAD&resourceKey=YWxsc2l4NnwzNDcyNDc3NTYxMzczODQ0NzkyfER8MTA5NjU1ODc)
*
* Modified and adapted by Dongwoo Lee
***************************************************************/
#include <TimerOne.h>

int analogPin0=0;
int analogPin1=1;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(2000);
  Timer1.attachInterrupt(AnalogAD);
  Timer1.start();
}

void AnalogAD()
{  
  int reading0=analogRead(analogPin0);  
  int reading1=analogRead(analogPin1);  

  float Voltage0=(float)reading0/1023*5;
  float Voltage1=(float)reading1/1023*5;

  if (Voltage1>1.65) digitalWrite(13,HIGH);
  else digitalWrite(13,LOW);

  String str=String(Voltage0,3) +","+ String(Voltage1,3);
  Serial.println(str);
}


void loop() {
}
