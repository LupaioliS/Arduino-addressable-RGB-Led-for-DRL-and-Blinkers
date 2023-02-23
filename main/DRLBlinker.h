#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>


	//#define NUM_ARGS_(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, N, ...) N
	//#define COUNT_ARGS(...) NUM_ARGS_(__VA_ARGS__, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

	#define RESET {1000, CRGB(0, 0, 0)}
	#define PIXEL(n, r, g, b) {n, CRGB(r, g, b)}
	#define FRAME(N, PX...) {N, new Pixel[N] { PX }}
	
	struct Pixel {
		uint16_t led_index;
		CRGB color;
	};

	struct Frame {
		int frame_size;
		Pixel* pixels;
		//int delay;
	};


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

			void setupAnimation(Frame* animation, uint16_t animation_size, uint16_t speed) {
				animation_speed = speed;
				current_animation = animation;
				max_frames = animation_size;
			}

			void startAnimation() {
				current_frame = 0;
				animation_active = true;
			}

			void stopAnimation() {
				current_frame = 0;
				animation_active = false;
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
						for(int i = 0; i < current_animation[current_frame].frame_size; i++) {
							switch(current_animation[current_frame].pixels[i].led_index) {
								case 1000: {
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
							current_frame = next_frame;
						}
					}
				} else {
					/*if(sizeof(current_animation) == 0) {
						_leds[0] = CRGB(0, 255, 0);
						FastLED.show();
					}*/
				}
			}
	};
#endif
