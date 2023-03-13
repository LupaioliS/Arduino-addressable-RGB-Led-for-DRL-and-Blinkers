#ifndef DRLBlinker_h
	#define DRLBlinker_h
	#include "Arduino.h"
	#include <FastLED.h>
	#include <arduino-timer.h>


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

	struct TimerStruct {
		void *p;
		int type;
		uint16_t led_index;
		int to;
	};

	template <uint8_t DATA_PIN, uint16_t NUM_LEDS> class DRLBlinker {
		private:
			CHSV DRLColor;
			CRGB _leds[NUM_LEDS];

			bool leds_busy[NUM_LEDS];
			bool leds_busy_setter[NUM_LEDS];
			bool leds_handled[NUM_LEDS];

			uint8_t leds_h[NUM_LEDS]; 
			uint8_t leds_s[NUM_LEDS];
			uint8_t leds_v[NUM_LEDS]; 

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
			int animation_busy = 0;

			uint16_t drlDim_currentValue = 0;

		    /*
			 * Timer Test
			 * 
		     */
			Timer<2, millis, TimerStruct*> timer;
			Timer<NUM_LEDS, millis> LED_DIM_timer;


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

				drlDim_currentValue = 1;
				static TimerStruct drlDim_TimerStruct;
				drlDim_TimerStruct.p = this;
				drlDim_TimerStruct.type = 1;
				timer.every(2, drlDim_Lambda, &drlDim_TimerStruct);				

				//timer.every(10, timerHandler, &t_struct);

				/*for(int i = 0; i < DRLColor.value; i++) {
					if(animation_active == true) break;
					fill_solid(_leds, NUM_LEDS, CHSV(DRLColor.hue, DRLColor.saturation, i));
					FastLED.show();
				}*/
			}

			uint16_t nextFrameIndex() {
				if(current_frame < max_frames - 1) {
					return current_frame + 1;
				} else {
					return -1;
				}
			}

			void setupAnimation(int animationID, Frame* animation, uint16_t animation_size, uint16_t speed) {
				Serial.print("setupAnimation ");
				Serial.println(animationID);
				//deleteAnimationMemory();
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

			static bool drlDim_Lambda(TimerStruct *timerStruct) {
				DRLBlinker *ptr = (DRLBlinker *)timerStruct->p;				
				switch(timerStruct->type) {
					case 1: { //Dim UP						
						return ptr->DRLdimUp();
					}
					case 2: { //Dim DOWN
						return ptr->DRLdimDown();
					}
				}				
		    }
			bool DRLdimUp() {	
 				if(animation_active == true) {
 					Serial.println("drlDim: Ended for animation_active");
 					onAnimationEnd(0);
 					return false;
 				}
				fill_solid(_leds, NUM_LEDS, CHSV(DRLColor.hue, DRLColor.saturation, drlDim_currentValue));
				FastLED.show();

				drlDim_currentValue++;
				/* Max DRL Value */
				if(drlDim_currentValue >= DRLColor.value) {
					Serial.println("drlDim: Ended for drlDim_currentValue");
					fill_solid(_leds, NUM_LEDS, CHSV(DRLColor.hue, DRLColor.saturation, DRLColor.value));
					FastLED.show();
					onAnimationEnd(0);
					return false;
				}
				return true;
			}
			bool DRLdimDown() {	
 				if(animation_active == true) {
 					onAnimationEnd(1);
 					return false;
 				}
				fill_solid(_leds, NUM_LEDS, CHSV(DRLColor.hue, DRLColor.saturation, drlDim_currentValue));
				FastLED.show();

				drlDim_currentValue--;
				/* Max DRL Value */
				if(drlDim_currentValue <= 0) {
					fill_solid(_leds, NUM_LEDS, CHSV(DRLColor.hue, DRLColor.saturation, DRLColor.value));
					FastLED.show();
					onAnimationEnd(1);
					return false;
				}
				return true;
			}

			/************************************************************************/
			static bool singleLedDimDown_Lambda(void *p) {
				DRLBlinker *ptr = (DRLBlinker *)p;					
				return ptr->singleLedDimDown();
		    }
		    bool singleLedDimDown() {
		    	int led_index = -1;
		    	int busy_leds = 0;
		    	int handled_leds = 0;

		    	for(int i = 0; i < NUM_LEDS; i++) {
		    		if(leds_busy[i] == true) {
		    			busy_leds++;
		    		}
		    		if(leds_handled[i] == true) {
		    			handled_leds++;
		    		}				
				}	
				for(int i = 0; i < NUM_LEDS; i++) {
					if(leds_busy[i] == true && leds_handled[i] == false) {
						led_index = i;
						leds_handled[i] = true;
						break;
					}
				}	

				if(led_index != -1) {	
					if(leds_v[led_index] > 1) {
	 					uint8_t newValue = leds_v[led_index] - 2;

	 					_leds[led_index] = CHSV(leds_h[led_index], leds_s[led_index], newValue);
	 					leds_v[led_index] = newValue;
	 					FastLED.show();

	 					if(busy_leds == handled_leds + 1) {
	 						for(int i = 0; i < NUM_LEDS; i++) {
								leds_handled[i] = false;
							}
	 					}
	 					return true;
	 				} else {
	 					_leds[led_index] = CHSV(leds_h[led_index], leds_s[led_index], 0);
	 					leds_v[led_index] = 0;
	 					FastLED.show();

	 					animation_busy--;
	 					leds_busy[led_index] = false;
	 					for(int i = 0; i < NUM_LEDS; i++) {
							leds_handled[i] = false;
						}
	 					return false;
	 				}
				}			
			}			
			/************************************************************************/
			/************************************************************************/
			static bool singleLedDimUp_Lambda(void *p) {
				DRLBlinker *ptr = (DRLBlinker *)p;					
				return ptr->singleLedDimUp();
		    }
		    bool singleLedDimUp() {
		    	int led_index = -1;
		    	int busy_leds = 0;
		    	int handled_leds = 0;

		    	for(int i = 0; i < NUM_LEDS; i++) {
		    		if(leds_busy[i] == true) {
		    			busy_leds++;
		    		}
		    		if(leds_handled[i] == true) {
		    			handled_leds++;
		    		}				
				}	
				for(int i = 0; i < NUM_LEDS; i++) {
					if(leds_busy[i] == true && leds_handled[i] == false) {
						led_index = i;
						leds_handled[i] = true;
						break;
					}
				}

				if(led_index != -1) {
					if(leds_v[led_index] < 255) {
	 					uint8_t newValue = leds_v[led_index] + 2;

	 					_leds[led_index] = CHSV(leds_h[led_index], leds_s[led_index], newValue);
	 					leds_v[led_index] = newValue;
	 					FastLED.show();

	 					if(busy_leds == handled_leds + 1) {
	 						for(int i = 0; i < NUM_LEDS; i++) {
								leds_handled[i] = false;
							}
	 					}
	 					return true;
	 				} else {
	 					_leds[led_index] = CHSV(leds_h[led_index], leds_s[led_index], 255);
	 					leds_v[led_index] = 255;
	 					FastLED.show();

	 					animation_busy--;
	 					leds_busy[led_index] = false;
	 					for(int i = 0; i < NUM_LEDS; i++) {
							leds_handled[i] = false;
						}
	 					return false;
	 				}
				}			
			}			
			/************************************************************************/

			void render() {
				timer.tick();
				LED_DIM_timer.tick();

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
									int lex_index_i = current_animation[current_frame].pixels[i].led_index;

									if(lex_index_i > 1000 && lex_index_i < 1001 + NUM_LEDS) { //Single led Dimdown
										if(leds_busy_setter[lex_index_i - 1001] == true) break;		

										leds_busy_setter[lex_index_i - 1001] = true;
										leds_busy[lex_index_i - 1001] = true;
										leds_handled[lex_index_i - 1001] = false;

										animation_busy++;

										/*Serial.print("singleLedDimDown for led: ");
										Serial.println(lex_index_i - 1001);*/

										LED_DIM_timer.every(5, singleLedDimDown_Lambda, this);	
										break;
									} else if(lex_index_i > 2000 && lex_index_i < 2001 + NUM_LEDS) { //Single led Dimup
										if(leds_busy_setter[lex_index_i - 2001] == true) break;	

										leds_busy_setter[lex_index_i - 2001] = true;
										leds_busy[lex_index_i - 2001] = true;
										leds_handled[lex_index_i - 2001] = false;

										animation_busy++;

										/*Serial.print("singleLedDimUp for led: ");
										Serial.println(lex_index_i - 2001);*/

										LED_DIM_timer.every(5, singleLedDimUp_Lambda, this);	
										break;
									} else {
										_leds[lex_index_i] = current_animation[current_frame].pixels[i].color;
										leds_h[lex_index_i] = current_animation[current_frame].pixels[i].color.hue;
										leds_s[lex_index_i] = current_animation[current_frame].pixels[i].color.saturation;
										leds_v[lex_index_i] = current_animation[current_frame].pixels[i].color.value;
										break;
									}									
								}
							}
						}

						FastLED.show();
						if(animation_busy == 0) {
							const uint16_t next_frame = nextFrameIndex();
							for(int i = 0; i < NUM_LEDS; i++) {
								leds_busy_setter[i] = false;
								leds_busy[i] = false;
								leds_handled[i] = false;
							}
							if(next_frame == -1) {
								stopAnimation();
							} else {
								current_frame = next_frame;
							}
						}						
					}
				}
			}
	};
#endif
