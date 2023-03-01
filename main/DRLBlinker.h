#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>


	//#define NUM_ARGS_(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, N, ...) N
	//#define COUNT_ARGS(...) NUM_ARGS_(__VA_ARGS__, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

	#define ALL_RESET {1000, CHSV(0, 0, 0)}

	#define PIXEL(n, h, s, v) {n, CHSV(h, s, v)}
	#define FRAME(N, PX...) {N, new Pixel[N] { PX }}
	
	struct Pixel {
		uint16_t led_index;
		CHSV color;
	};

	struct Frame {
		int frame_size;
		Pixel* pixels;
		//int delay;
	};


	template <uint8_t DATA_PIN, uint16_t NUM_LEDS> class DRLBlinker {
		private:
			CHSV DRLColor;
			CRGB _leds[NUM_LEDS];

			uint16_t animation_speed = 500;
			uint16_t current_frame = 0;
			uint16_t max_frames;
			Frame* current_animation;
			int current_animation_id;
			volatile unsigned long last_frame_time;
			void (*onAnimationEnd)(int);

		public:
			const char* DRLName;
			bool animation_active = false;

			DRLBlinker(const char* name, CHSV color) : DRLName(name) {
				setDRLColor(color);
			}	

			void initialize(int (*callback)(int)) {
				FastLED.addLeds<WS2812, DATA_PIN, GRB>(_leds, NUM_LEDS);

				onAnimationEnd = callback;

				reset();
				//showDRL();
			}

			void setDRLColor(CHSV color) {
				DRLColor = color;
			}

			void reset() {
				fill_solid(_leds, NUM_LEDS, CRGB::Black);
				FastLED.show();
			}

			void showDRL() {
				Serial.println("showDRL");
				for(int i = 0; i < DRLColor.value; i++) {
					if(animation_active == true) break;
					fill_solid(_leds, NUM_LEDS, CHSV(DRLColor.hue, DRLColor.saturation, i));
					FastLED.show();
				}
			}

			uint16_t nextFrameIndex() {
				if(current_frame < max_frames - 1) {
					return current_frame + 1;
				} else {
					return -1;
				}
			}

			void setupAnimation(int animationID, Frame* animation, uint16_t animation_size, uint16_t speed) {
				Serial.println("setupAnimation");
				deleteAnimationMemory();
				animation_speed = speed;
				current_animation = animation;
				max_frames = animation_size;
				current_animation_id = animationID;
			}

			void startAnimation(int animationID) {
				if(animationID == current_animation_id) {
					current_frame = 0;
					animation_active = true;
				}
			}

			void stopAnimation() {
				current_frame = 0;
				animation_active = false;

				onAnimationEnd(current_animation_id);
			}

			void deleteAnimationMemory() {
				for(int i = 0; i < sizeof(current_animation) / sizeof(Frame); i++) {
					delete current_animation[i].pixels;
				}
				delete current_animation;
			}

			void render() {
				volatile unsigned long currentTime = millis();

				if(animation_active) {
					if(currentTime - last_frame_time > animation_speed) {
						last_frame_time = currentTime;
						for(int i = 0; i < current_animation[current_frame].frame_size; i++) {
							switch(current_animation[current_frame].pixels[i].led_index) {
								case 1000: { //ALL_RESET
									reset();
									break;
								}
								default: {
									/*CHSV currentColor = rgb2hsv_approximate(_leds[current_animation[current_frame].pixels[i].led_index - 1001]);*/
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
				}
			}
	};
#endif
