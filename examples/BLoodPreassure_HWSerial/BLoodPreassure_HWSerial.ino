#include <Ardunic_BloodPressure.h>

// Define the Hardware serial port for your arduino
BloodPressure info(&Serial2);  // Hardware serial2 for arduino mega was used as an example.


void setup(){
Serial.begin(9600);   // define the boudrate for your serial monitor.
Serial2.begin(9600);  // define the boudrate for Serial2 port to communicate with our device.
}

void loop(){
info.update(); // Update info from Blood Pressure Device
Serial.print("SYS = " + String(info.GetSYS()));  // Get systolic blood pressure.
Serial.print(" DIA = " + String(info.GetDIA())); // Get diastolic blood pressure.
Serial.println(" HR = " + String(info.GetHR())); // Get Heart rate.
delay(1000);
}
