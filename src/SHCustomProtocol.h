/*
  SHCustomProtocol class usage / documentation:
  https://github.com/zegreatclan/SimHub/wiki/Custom-Arduino-hardware-support
*/

#ifndef __SHCUSTOMPROTOCOL_H__
#define __SHCUSTOMPROTOCOL_H__

#include <Arduino.h>
#include "SimpleDisplay.h"

class SHCustomProtocol {
private:

public:

	void setup() {
    
    for (int i = 2; i < 9+NUM_RPM_LEDS; i++) {
      pinMode(i, OUTPUT);
    }

    if (SHOW_STARTUP_ANIMATION) {
      startupAnimation();
    }
    
	}

	void read() {

    int gear = FlowSerialReadStringUntil(';').toInt();
    int rpm = FlowSerialReadStringUntil(';').toInt();
    int maxRpm = FlowSerialReadStringUntil('\n').toInt();

    if (rpm >= maxRpm) {
      // blink LED if shift light is on
      showGear(gear);
      delay(50);
      showGear(-2);
      delay(50);
    } else {
      // just show gear if shift light not on
      showGear(gear);
    }

    // calculate number of LEDs to show
    int rpmLeds = (int) (((float) (rpm) / (maxRpm)) * NUM_RPM_LEDS);

    // display RPMs
    showRPM(rpmLeds);
    
	}

	void loop() {
	}

	void idle() {
	}
 
};

#endif
