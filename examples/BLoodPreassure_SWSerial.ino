#include <Ardunic_BloodPressure.h>

// Define the RX pin & TX pin for your Software Serial Port.
BloodPressure info(8, 7); // RX pin,TX pin

void setup(){
Serial.begin(9600);  // define the boudrate for your serial monitor
}

void loop(){
info.update(); // Update info from Blood Pressure Device
Serial.print("SYS = " + String(info.GetSYS()));  // Get systolic blood pressure.
Serial.print(" DIA = " + String(info.GetDIA())); // Get diastolic blood pressure.
Serial.println(" HR = " + String(info.GetHR())); // Get Heart rate.
delay(1000);
}
