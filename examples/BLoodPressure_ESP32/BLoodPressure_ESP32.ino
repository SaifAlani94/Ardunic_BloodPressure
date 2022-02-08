#include <Ardunic_BloodPressure.h>


HardwareSerial SerialB(2);
BloodPressure info(&SerialB);


void setup(){
  Serial.begin(9600);
  SerialB.begin(9600);
}

void loop(){
info.update();
Serial.print("SYS = " + String(info.GetSYS()));
Serial.print(" DIA = " + String(info.GetDIA()));
Serial.println(" HR = " + String(info.GetHR()));
  delay(1000);
}
