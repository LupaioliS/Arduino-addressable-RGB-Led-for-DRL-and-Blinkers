#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>


	template <uint8_t DATA_PIN, uint16_t NUM_LEDS> class DRLBlinker {
		public:
			const char* DRLName;
			CRGB _leds[NUM_LEDS];

			DRLBlinker(const char* name) : DRLName(name) {}	

			void initialize() {
				FastLED.addLeds<WS2812, DATA_PIN, GRB>(_leds, NUM_LEDS);

				/*
					Reset all LEDS
				*/
				for(uint8_t i = 0; i <= NUM_LEDS; i++) {
					_leds[i] = CRGB(0, 0, 0);
				}
				FastLED.show();
			}
	};
#endif
