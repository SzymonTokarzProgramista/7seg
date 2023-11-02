#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 4;   
  byte digitPins[] = {12, 9, 8, 6};
  byte segmentPins[] = {11, 7, 4, 2, 1, 10, 5, 3};
  bool resistorsOnSegments = true; // Use 'true' if on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
}
int i=0;


void loop() {
    unsigned long timerGlobal = millis()/100;
    if (timerGlobal>9999){
      timerGlobal=0;
    }
    sevseg.setNumber(timerGlobal, -1);
    sevseg.refreshDisplay();
}