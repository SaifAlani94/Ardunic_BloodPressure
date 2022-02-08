/*
  Ardunic_BloodPressure.cpp - Library for getting blood pressure and Heart rate.
  Created by Saif Muqdad Alani, 2, Feb, 2022, in Ardunic.
  Email : saifmuqdad@gmail.com
  Released into the public domain.
*/

#include "Ardunic_BloodPressure.h"
#include <stdio.h>
#include "SerialTransfer.h"

#define BloodPressure_BAUD_RATE 9600
extern HardwareSerial Serial;

SerialTransfer myTransfer;
struct package {
  float SYS;
  float DIA;
  float HR;
};
typedef struct package Package;
Package data;


#if defined(BloodPressure_SOFTSERIAL)
BloodPressure::BloodPressure(uint8_t receivePin, uint8_t transmitPin)
{
    SoftwareSerial *port = new SoftwareSerial(receivePin, transmitPin);
    port->begin(BloodPressure_BAUD_RATE);
    this->_serial = port;
    this->_isSoft = true;
    myTransfer.begin(*port);
}
#endif


BloodPressure::BloodPressure(HardwareSerial* port)
{
    port->begin(BloodPressure_BAUD_RATE);
    this->_serial = port;
    this->_isSoft = false;
    myTransfer.begin(*port);
}


BloodPressure::~BloodPressure()
{
    if(_isSoft)
        delete this->_serial;
}

void BloodPressure::update()
{
  if(myTransfer.available()){
    uint16_t recSize = 0;
    recSize = myTransfer.rxObj(data, recSize);}
} 


float BloodPressure::GetSYS()
{
return data.SYS;
} 

float BloodPressure::GetDIA()
{
return data.DIA;
} 

float BloodPressure::GetHR()
{
return data.HR;
} 

