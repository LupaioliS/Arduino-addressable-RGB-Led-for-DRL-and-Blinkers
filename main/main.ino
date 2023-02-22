#include "DRLBlinker.h"


DRLBlinker<7, 30> leftDRL("leftDRL", CRGB(255,255,255),  CRGB(255, 35, 0));
DRLBlinker<8, 30> rightDRL("rightDRL", CRGB(255,255,255), CRGB(255, 35, 0));

void setup() {
	leftDRL.initialize();
	rightDRL.initialize();
} 

void loop() {

}