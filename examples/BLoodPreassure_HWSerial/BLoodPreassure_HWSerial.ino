#include <Ardunic_BloodPressure.h>


BloodPressure info(&Serial2);


void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop(){
info.update();
Serial.print("SYS = " + String(info.GetSYS()));
Serial.print(" DIA = " + String(info.GetDIA()));
Serial.println(" HR = " + String(info.GetHR()));
delay(1000);
}
