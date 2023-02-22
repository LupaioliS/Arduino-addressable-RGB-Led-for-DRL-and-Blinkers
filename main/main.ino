#include "DRLBlinker.h"


DRLBlinker<7, 30> leftDRL("leftDRL");
DRLBlinker<8, 30> rightDRL("rightDRL");

void setup() {
	leftDRL.initialize();
	rightDRL.initialize();
} 

void loop() {

}