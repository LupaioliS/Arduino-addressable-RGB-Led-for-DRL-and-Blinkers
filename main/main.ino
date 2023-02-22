#include "DRLBlinker.h"


DRLBlinker<7, 30> leftDRL("leftDRL");
DRLBlinker<8, 30> rightDRL("rightDRL");

void setup() {
	leftDRL.initialize();
	rightDRL.initialize();
} 

void loop() {
  /*for (int i = 0; i <= 143; i++) {
	leds[i] = CRGB ( 0, 0, 0);
  }
  FastLED.show();
  delay(100);
  for (int i = 20; i >= 0; i--) {
	leds[i] = CRGB (255, 35, 0);
	FastLED.show();
	delay(30);
  }
  delay(300);

  for (int i = 0; i <= 143; i++) {
	leds[i] = CRGB ( 0, 0, 0);
  }
  FastLED.show();
  delay(100);
  for (int i = 20; i >= 0; i--) {
	leds[i] = CRGB (255, 35, 0);
	FastLED.show();
	delay(30);
  }
  delay(300);

  for (int i = 0; i <= 143; i++) {
	leds[i] = CRGB ( 0, 0, 0);
  }
  FastLED.show();
  delay(100);
  for (int i = 20; i >= 0; i--) {
	leds[i] = CRGB (255, 35, 0);
	FastLED.show();
	delay(30);
  }
  delay(300);

  for (int i = 0; i <= 20; i++) {
	leds[i] = CRGB ( 255, 255, 255);
  }
  FastLED.show();
  delay(3000);*/
}