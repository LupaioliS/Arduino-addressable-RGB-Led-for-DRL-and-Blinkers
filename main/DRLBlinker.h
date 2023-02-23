#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>
	
	#define RESET {-1, CRGB(0, 0, 0)}

	struct Pixel {
		uint16_t led_index;
		CRGB color;
	};

	struct Frame {
		Pixel* pixels;
		//int delay;
	};

	//std::vector<Frame> frames;

	template <uint8_t DATA_PIN, uint16_t NUM_LEDS> class DRLBlinker {
		private:
			CRGB DRLColor;
			CRGB _leds[NUM_LEDS];

			uint16_t animation_speed = 500;
			bool animation_active = false;
			uint16_t current_frame = 0;
			uint16_t max_frames;
			Frame* current_animation;

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

			void setupAnimation(Frame animation[], uint16_t speed) {
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
				deleteAnimationMemory();
			}

			void deleteAnimationMemory() {
				for(int i = 0; i < sizeof(current_animation) / sizeof(Frame); i++) {
					delete current_animation[i].pixels;
				}
				delete current_animation;
			}

			void render() {
				if(animation_active) {
					EVERY_N_MILLISECONDS(animation_speed) {
						for(int i = 0; i < sizeof(current_animation[current_frame].pixels); i++) {
							switch(current_animation[current_frame].pixels[i].led_index) {
								case -1: {
									reset();
									break;
								}
								default: {
									_leds[current_animation[current_frame].pixels[i].led_index] = current_animation[current_frame].pixels[i].color;
									break;
								}
							}
						}

						FastLED.show();

						const uint16_t next_frame = nextFrameIndex();
						if(next_frame == -1) {
							stopAnimation();
						} else {
							//if(current_animation[current_frame].delay != 0) delay(current_animation[current_frame].delay);
							current_frame = next_frame;
						}
					}
				} else {
					if(sizeof(current_animation) == 0) {
						_leds[0] = CRGB(0, 255, 0);
						FastLED.show();
					}
				}
			}
	};
#endif
