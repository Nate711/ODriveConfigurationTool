// Extreme Mobility Doggo Code
// Set ODrive parameters through the teensy

#include "Arduino.h"
#include "ODriveArduino.h"
#include "globals.hpp"

void setup() {
    #ifndef __arm__
    Serial.println("Must run on Teensy 3.5");
    while(true){}
    #endif

    // Begin at 115200 BAUD
    Serial.begin(115200);
    // Wait for USB Serial.
    while (!Serial) {}

    // Make sure the custom firmware is loaded because the default BAUD is 115200
    odrv0Serial.begin(500000);
    odrv1Serial.begin(500000);
    odrv2Serial.begin(500000);
    odrv3Serial.begin(500000);
}

void loop() {
    odrv0Interface.ReadProperty("axis0.controller.config.vel_limit");
    Serial.print("Old: ");
    Serial.println(Serial.readString());
    odrv0Interface.SetProperty("axis0.controller.config.vel_limit","80000");
    delay(100);
    odrv0Interface.ReadProperty("axis0.controller.config.vel_limit");
    Serial.print("New: ");
    Serial.println(Serial.readString());

    while(true) {}
}
