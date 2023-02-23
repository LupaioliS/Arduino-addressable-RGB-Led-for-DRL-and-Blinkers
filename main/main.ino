#include "DRLBlinker.h"

#define LEDS_PER_STRIP 30


DRLBlinker<7, LEDS_PER_STRIP> lxDRL("lxDRL", CRGB(255,255,255));
DRLBlinker<8, LEDS_PER_STRIP> rxDRL("rxDRL", CRGB(255,255,255));



/*Frame singleFrame[] = {
	RESET,
	{0, 0, 	CRGB(255, 35, 0)}, 
	{1, 0, 	CRGB(255, 35, 0)}, 
	{2, 0, 	CRGB(255, 35, 0)}, 
	{3, 0, 	CRGB(255, 35, 0)},
	{4, 0, 	CRGB(255, 35, 0)},
	{5, 0, 	CRGB(255, 35, 0)},
	{6, 0, 	CRGB(255, 35, 0)},
	{7, 0, 	CRGB(255, 35, 0)},
	{8, 0, 	CRGB(255, 35, 0)},
	{9, 0, 	CRGB(255, 35, 0)},
	{10, 0, CRGB(255, 35, 0)},
	{11, 0, CRGB(255, 35, 0)},
	{12, 0, CRGB(255, 35, 0)},
	{13, 0, CRGB(255, 35, 0)},
	{14, 0, CRGB(255, 35, 0)},
	{15, 0, CRGB(255, 35, 0)},
	{16, 0, CRGB(255, 35, 0)},
	{17, 0, CRGB(255, 35, 0)},
	{18, 0, CRGB(255, 35, 0)},
	{19, 0, CRGB(255, 35, 0)},
	{20, 0, CRGB(255, 35, 0)},
	{21, 0, CRGB(255, 35, 0)},
	{22, 0, CRGB(255, 35, 0)},
	{23, 0, CRGB(255, 35, 0)},
	{24, 0, CRGB(255, 35, 0)},
	{25, 0, CRGB(255, 35, 0)},
	{26, 0, CRGB(255, 35, 0)},
	{27, 0, CRGB(255, 35, 0)},
	{28, 0, CRGB(255, 35, 0)},
	{29, 0, CRGB(255, 35, 0)}
};
*/


Frame blink[2] = {
	new Pixel[2] {
		RESET,
		{0, CRGB(255, 35, 0)}
	},
	new Pixel[1] {
		{1, CRGB(255, 35, 0)}
	}
};



void setup() {
	lxDRL.initialize();
	rxDRL.initialize();


	lxDRL.setupAnimation(blink, 2000);
} 

void loop() {
	/* 
	 * lxDRL animation
	 */
	lxDRL.render();
}