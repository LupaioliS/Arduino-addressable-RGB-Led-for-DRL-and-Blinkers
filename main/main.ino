#include "DRLBlinker.h"

#define LEDS_PER_STRIP 31


DRLBlinker<7, LEDS_PER_STRIP> lxDRL("lxDRL", CRGB(0, 0, 0));
//DRLBlinker<8, LEDS_PER_STRIP> rxDRL("rxDRL", CRGB(255,255,255));



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

#define BLINK_FRAMES 32
Frame blink[BLINK_FRAMES] = {
	{2, new Pixel[2] { 
		RESET, {0, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{1, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{2, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{3, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{4, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{5, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{6, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{7, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{8, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{9, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{10, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{11, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{12, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{13, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{14, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{15, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{16, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{17, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{18, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{19, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{20, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{21, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{22, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{23, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{24, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{25, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{26, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{27, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{28, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{29, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		{30, CRGB(255, 35, 0)}
	}},
	{1, new Pixel[1] { 
		RESET
	}}
};


/*
#define REP0(X)
#define REP1(X...) X
#define REP2(X...) REP1(X), X
#define REP3(X...) REP2(X), X
#define REP4(X...) REP3(X), X
#define REP5(X...) REP4(X), X
#define REP6(X...) REP5(X), X
#define REP7(X...) REP6(X), X
#define REP8(X...) REP7(X), X
#define REP9(X...) REP8(X), X
#define REP10(X...) REP9(X), X


#define REP(HUNDREDS,TENS,ONES,X) \
  REP##HUNDREDS(REP10(REP10(X))) \
  REP##TENS(REP10(X)) \
  REP##ONES(X)*/


#define STARTUP_FRAMES 16
Frame startup[STARTUP_FRAMES] = {
	FRAME(
		2,
		RESET,
		PIXEL(15, 20, 20, 20)
	),
	FRAME(
		3,
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20)
	),
	FRAME(
		5,
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20)
	),
	FRAME(
		7,
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20)
	),
	FRAME(
		9,
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20)
	),
	FRAME(
		11,
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20)
	),
	FRAME(
		13,
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20)
	),
	FRAME(
		15,
		PIXEL(8, 20, 20, 20),
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20),
		PIXEL(22, 20, 20, 20)
	),
	FRAME(
		17,
		PIXEL(7, 20, 20, 20),
		PIXEL(8, 20, 20, 20),
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20),
		PIXEL(22, 20, 20, 20),
		PIXEL(23, 20, 20, 20)
	),
	FRAME(
		19,
		PIXEL(6, 20, 20, 20),
		PIXEL(7, 20, 20, 20),
		PIXEL(8, 20, 20, 20),
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20),
		PIXEL(22, 20, 20, 20),
		PIXEL(23, 20, 20, 20),
		PIXEL(24, 20, 20, 20)
	),
	FRAME(
		21,
		PIXEL(5, 20, 20, 20),
		PIXEL(6, 20, 20, 20),
		PIXEL(7, 20, 20, 20),
		PIXEL(8, 20, 20, 20),
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20),
		PIXEL(22, 20, 20, 20),
		PIXEL(23, 20, 20, 20),
		PIXEL(24, 20, 20, 20),
		PIXEL(25, 20, 20, 20)
	),
	FRAME(
		23,
		PIXEL(4, 20, 20, 20),
		PIXEL(5, 20, 20, 20),
		PIXEL(6, 20, 20, 20),
		PIXEL(7, 20, 20, 20),
		PIXEL(8, 20, 20, 20),
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20),
		PIXEL(22, 20, 20, 20),
		PIXEL(23, 20, 20, 20),
		PIXEL(24, 20, 20, 20),
		PIXEL(25, 20, 20, 20),
		PIXEL(26, 20, 20, 20)
	),
	FRAME(
		25,
		PIXEL(3, 20, 20, 20),
		PIXEL(4, 20, 20, 20),
		PIXEL(5, 20, 20, 20),
		PIXEL(6, 20, 20, 20),
		PIXEL(7, 20, 20, 20),
		PIXEL(8, 20, 20, 20),
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20),
		PIXEL(22, 20, 20, 20),
		PIXEL(23, 20, 20, 20),
		PIXEL(24, 20, 20, 20),
		PIXEL(25, 20, 20, 20),
		PIXEL(26, 20, 20, 20),
		PIXEL(27, 20, 20, 20)
	),
	FRAME(
		27,
		PIXEL(2, 20, 20, 20),
		PIXEL(3, 20, 20, 20),
		PIXEL(4, 20, 20, 20),
		PIXEL(5, 20, 20, 20),
		PIXEL(6, 20, 20, 20),
		PIXEL(7, 20, 20, 20),
		PIXEL(8, 20, 20, 20),
		PIXEL(9, 20, 20, 20),
		PIXEL(10, 20, 20, 20),
		PIXEL(11, 20, 20, 20),
		PIXEL(12, 20, 20, 20),
		PIXEL(13, 20, 20, 20),
		PIXEL(14, 20, 20, 20),
		PIXEL(15, 20, 20, 20),
		PIXEL(16, 20, 20, 20),
		PIXEL(17, 20, 20, 20),
		PIXEL(18, 20, 20, 20),
		PIXEL(19, 20, 20, 20),
		PIXEL(20, 20, 20, 20),
		PIXEL(21, 20, 20, 20),
		PIXEL(22, 20, 20, 20),
		PIXEL(23, 20, 20, 20),
		PIXEL(24, 20, 20, 20),
		PIXEL(25, 20, 20, 20),
		PIXEL(26, 20, 20, 20),
		PIXEL(27, 20, 20, 20),
		PIXEL(28, 20, 20, 20)
	)
};

int val;
bool blinkState = true;
volatile unsigned long blinkTime = 0; 
volatile unsigned long currentTime; 
bool DRLAccesa = true;

void setup() {
	//Serial.begin(9600);

  	pinMode(5, INPUT);

	lxDRL.initialize();
	//rxDRL.initialize();

	lxDRL.setupAnimation(startup, STARTUP_FRAMES, 60);
	lxDRL.startAnimation();

	//lxDRL.setupAnimation(blink, BLINK_FRAMES, 20);
	//lxDRL.startAnimation();
} 

void loop() {
	val = digitalRead(5); //1

  	currentTime = millis(); //3000
  	
  	//3110 - 3000 = 110 > 100 si
  	if(currentTime - blinkTime > 100) {
		if(val == LOW && blinkState == false) {
			blinkState = true;
			DRLAccesa = false;
			//Serial.println("ACCESO");
			blinkTime = currentTime;
			lxDRL.startAnimation();
		} else if(val == HIGH && blinkState == true) {
			blinkState = false;
			DRLAccesa = false;
			//Serial.println("SPENTO");
			blinkTime = currentTime;
			//lxDRL.stopAnimation();
		}
  	}

  	/*if(currentTime - blinkTime > 1000 && DRLAccesa == false) {
  		//Serial.println("FERMO DA TROPPO");
  		DRLAccesa = true;
  		lxDRL.reset();
  		lxDRL.showDRL();
  	}*/
	

	/* 
	 * lxDRL animation
	 */
	lxDRL.render();
}