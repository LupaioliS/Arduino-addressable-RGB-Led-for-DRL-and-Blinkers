#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>
	
	#define RESET {-1, 0, CRGB(0, 0, 0)}

	struct Animation {
		uint16_t led_index;
		int delay;
		CRGB color;
	};

	template <uint8_t DATA_PIN, uint16_t NUM_LEDS> class DRLBlinker {
		private:
			CRGB DRLColor;
			CRGB _leds[NUM_LEDS];

			uint16_t animation_speed = 500;
			bool animation_active = false;
			uint16_t current_frame = 0;
			uint16_t max_frames;
			Animation* current_animation;

		public:
			const char* DRLName;
		

			DRLBlinker(const char* name, CRGB color) : DRLName(name) {
				setDRLColor(color);
			}	

			void initialize() {
				FastLED.addLeds<WS2812, DATA_PIN, GRB>(_leds, NUM_LEDS);

				reset();
				showDRL();
			}

			void setDRLColor(CRGB color) {
				DRLColor = color;
			}

			void reset() {
				fill_solid(_leds, NUM_LEDS, CRGB::Black);
				FastLED.show();
			}

			void showDRL() {
				fill_solid(_leds, NUM_LEDS, DRLColor);
				FastLED.show();
			}

			uint16_t nextFrameIndex() {
				if(current_frame < max_frames - 1) {
					return current_frame + 1;
				} else {
					return -1;
				}
			}

			void setupAnimation(Animation animation[], uint16_t speed) {
				animation_speed = speed;
				current_animation = animation;
				max_frames = sizeof(animation);
			}

			void startAnimation() {
				current_frame = 0;
				animation_active = true;
			}

			void stopAnimation() {
				current_frame = 0;
				animation_active = false;
			}

			void render() {
				if(animation_active) {
					EVERY_N_MILLISECONDS(animation_speed) {
						switch(current_animation[current_frame].led_index) {
							case -1: {
								reset();
								break;
							}
							default: {
								_leds[current_animation[current_frame].led_index] = current_animation[current_frame].color;
								FastLED.show();
								break;
							}
						}
						const uint16_t next_frame = nextFrameIndex();
						if(next_frame == -1) {
							stopAnimation();
						} else {
							if(current_animation[current_frame].delay != 0) delay(current_animation[current_frame].delay);
							current_frame = next_frame;
						}
					}
				}
			}
	};
#endif
