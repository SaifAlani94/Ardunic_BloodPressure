# Ardunic_BloodPressure
Arduino library for the Ardunic Blood Pressure Device. This library is very simple and intuitive to use.

For example, we can get the systolic blood pressure, diastolic blood pressure, & Heart rate with just a few lines of code:
```
#include <Ardunic_BloodPressure.h>
BloodPressure info(8, 7);

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
```

See the included [examples](https://github.com/SaifAlani94/Ardunic_BloodPressure/tree/master/examples) for more.


## Installation
This library uses the [SerialTransfer](https://www.arduino.cc/reference/en/libraries/serialtransfer/) library "This library was tested on SerialTransfer library Version 3.1.2", so you will need to have this installed. Install it using the Library Manager in the Arduino IDE.


## Wiring the Ardunic Blood Pressure device
For wiring the Ardunic Blood Pressure device you need to use a serial port ( Hardware or software ) UART serial port, then follow as below.

![image](https://user-images.githubusercontent.com/8711894/152967269-8b9417d3-1566-4a25-9787-d548afdc202a.png)
