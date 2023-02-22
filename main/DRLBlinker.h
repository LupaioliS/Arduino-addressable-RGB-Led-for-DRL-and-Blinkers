#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>


	template <uint8_t DATA_PIN, uint16_t NUM_LEDS> class DRLBlinker {
		public:
			const char* DRLName;
			CRGB _leds[NUM_LEDS];
			CRGB DRLColor;
			CRGB BlinkerColor;

			DRLBlinker(const char* name, CRGB color, CRGB blinker_color) : DRLName(name) {
				setDRLColor(color);
				setBlinkerColor(blinker_color);
			}	

			void initialize() {
				FastLED.addLeds<WS2812, DATA_PIN, GRB>(_leds, NUM_LEDS);

				reset();
				showDRL();
			}

			void setDRLColor(CRGB color) {
				DRLColor = color;
			}

			void setBlinkerColor(CRGB color) {
				BlinkerColor = color;
			}

			void reset() {
				fill_solid(_leds, NUM_LEDS, CRGB::Black);
				FastLED.show();
			}

			void showDRL() {
				fill_solid(_leds, NUM_LEDS, DRLColor);
				FastLED.show();
			}
	};
#endif
