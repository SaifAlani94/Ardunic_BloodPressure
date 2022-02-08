#include <Ardunic_BloodPressure.h>


BloodPressure info(8, 7); // RX,TX 

void setup(){
Serial.begin(9600);
}

void loop(){
info.update();
Serial.print("SYS = " + String(info.GetSYS()));
Serial.print(" DIA = " + String(info.GetDIA()));
Serial.println(" HR = " + String(info.GetHR()));
delay(1000);
}
