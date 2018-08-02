#ifndef GLOBALS_H
#define GLOBALS_H

#include "Arduino.h"
#include "ODriveArduino.h"

//------------------------------------------------------------------------------
// Helper utilities
// Add support for using "<<" to stream stuff to the usb serial
template<class T> inline Print& operator <<(Print &obj,     T arg) { obj.print(arg);    return obj; }
template<>        inline Print& operator <<(Print &obj, float arg) { obj.print(arg, 4); return obj; }

//------------------------------------------------------------------------------
// Initialize objects related to ODrives

// TODO: There's a lot of repetition in this section that's hinting we should
// somehow encapsulate more behavior. We could put the serial references inside
// the ODriveArduino class and put the pos estimate struct in there too

// Make references to Teensy <-> computer serial (aka USB) and the ODrive(s)
HardwareSerial& odrv0Serial = Serial1;
HardwareSerial& odrv1Serial = Serial2;
HardwareSerial& odrv2Serial = Serial3;
HardwareSerial& odrv3Serial = Serial4;

// ODriveArduino objects
// These objects are responsible for sending commands to the ODrive over their
// respective serial port
ODriveArduino odrv0Interface(odrv0Serial);
ODriveArduino odrv1Interface(odrv1Serial);
ODriveArduino odrv2Interface(odrv2Serial);
ODriveArduino odrv3Interface(odrv3Serial);

#endif
