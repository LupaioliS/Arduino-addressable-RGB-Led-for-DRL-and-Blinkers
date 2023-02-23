#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>
	
	#define RESET {-1, 0, CRGB(0, 0, 0)}

	struct Animation {
		int led_index;
		int timing;
		CRGB color;
	};

	template <uint8_t DATA_PIN, uint16_t NUM_LEDS> class DRLBlinker {
		private:
			CRGB DRLColor;
			CRGB BlinkerColor;
			CRGB _leds[NUM_LEDS];

			uint16_t animation_speed = 500;
			bool animation_active = false;
			uint16_t current_frame = 0;

		public:
			const char* DRLName;
		

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

			void render() {
				if(animation_active) {
					EVERY_N_MILLISECONDS(animation_speed) {
						
					}
				}
			}
	};
#endif
