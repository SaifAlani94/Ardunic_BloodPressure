/*
  Ardunic_BloodPressure.h - Library for getting blood pressure and Heart rate.
  Created by Saif Muqdad Alani, 2, Feb, 2022, in Ardunic.
  Email : saifmuqdad@gmail.com
  Released into the public domain.
*/

#ifndef Ardunic_BloodPressure
#define Ardunic_BloodPressure


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// #define BloodPressure_NO_SWSERIAL
#if (not defined(BloodPressure_NO_SWSERIAL)) && (defined(__AVR__) || defined(ESP8266) && (not defined(ESP32)))
#define BloodPressure_SOFTSERIAL
#endif

#if defined(BloodPressure_SOFTSERIAL)
#include <SoftwareSerial.h>
#endif




class BloodPressure
{
  public:

  #if defined(BloodPressure_SOFTSERIAL)
      BloodPressure(uint8_t receivePin, uint8_t transmitPin);
  #endif
      BloodPressure(HardwareSerial* port);
      ~BloodPressure();

    void  update();
    float GetSYS();
    float GetDIA();
    float GetHR();
  private:

    Stream* _serial; // Serial interface
    bool _isSoft;    // Is serial interface software
};

#endif

