#include "DRLBlinker.h"

#define LEDS_PER_STRIP 31


DRLBlinker<7, LEDS_PER_STRIP> lxDRL("lxDRL", CHSV(0, 0, 255));
//DRLBlinker<8, LEDS_PER_STRIP> rxDRL("rxDRL", CRGB(255,255,255));



#define BLINK_FRAMES 32
Frame blink[BLINK_FRAMES] = {
	FRAME(
		2, 
		ALL_RESET, 
		PIXEL(0, 8, 255, 255)
	),
	FRAME(
		1,
		PIXEL(1, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(2, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(3, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(4, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(5, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(6, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(7, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(8, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(9, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(10, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(11, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(12, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(13, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(14, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(15, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(16, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(17, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(18, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(19, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(20, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(21, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(22, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(23, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(24, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(25, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(26, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(27, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(28, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(29, 8, 255, 255)
	),
	FRAME(
		1, 
		PIXEL(30, 8, 255, 255)
	),
	FRAME(
		1,
		ALL_RESET
	)
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


#define STARTUP_FRAMES 14
Frame startup[STARTUP_FRAMES] = {
	FRAME(
		2,
		ALL_RESET,
		PIXEL(15, 213, 255, 255)
	),
	FRAME(
		3,
		PIXEL(14, 213, 255, 255),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 213, 255, 255)
	),
	FRAME(
		5,
		PIXEL(13, 213, 255, 255),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 213, 255, 255)
	),
	FRAME(
		7,
		PIXEL(12, 213, 255, 255),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 213, 255, 255)
	),
	FRAME(
		9,
		PIXEL(11, 213, 255, 255),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 213, 255, 255)
	),
	FRAME(
		11,
		PIXEL(10, 213, 255, 255),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 213, 255, 255)
	),
	FRAME(
		13,
		PIXEL(9, 213, 255, 255),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 213, 255, 255)
	),
	FRAME(
		15,
		PIXEL(8, 213, 255, 255),
		PIXEL(9, 0, 0, 50),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 0, 0, 50),
		PIXEL(22, 213, 255, 255)
	),
	FRAME(
		17,
		PIXEL(7, 213, 255, 255),
		PIXEL(8, 0, 0, 50),
		PIXEL(9, 0, 0, 50),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 0, 0, 50),
		PIXEL(22, 0, 0, 50),
		PIXEL(23, 213, 255, 255)
	),
	FRAME(
		19,
		PIXEL(6, 213, 255, 255),
		PIXEL(7, 0, 0, 50),
		PIXEL(8, 0, 0, 50),
		PIXEL(9, 0, 0, 50),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 0, 0, 50),
		PIXEL(22, 0, 0, 50),
		PIXEL(23, 0, 0, 50),
		PIXEL(24, 213, 255, 255)
	),
	FRAME(
		21,
		PIXEL(5, 213, 255, 255),
		PIXEL(6, 0, 0, 50),
		PIXEL(7, 0, 0, 50),
		PIXEL(8, 0, 0, 50),
		PIXEL(9, 0, 0, 50),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 0, 0, 50),
		PIXEL(22, 0, 0, 50),
		PIXEL(23, 0, 0, 50),
		PIXEL(24, 0, 0, 50),
		PIXEL(25, 213, 255, 255)
	),
	FRAME(
		23,
		PIXEL(4, 213, 255, 255),
		PIXEL(5, 0, 0, 50),
		PIXEL(6, 0, 0, 50),
		PIXEL(7, 0, 0, 50),
		PIXEL(8, 0, 0, 50),
		PIXEL(9, 0, 0, 50),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 0, 0, 50),
		PIXEL(22, 0, 0, 50),
		PIXEL(23, 0, 0, 50),
		PIXEL(24, 0, 0, 50),
		PIXEL(25, 0, 0, 50),
		PIXEL(26, 213, 255, 255)
	),
	FRAME(
		25,
		PIXEL(3, 213, 255, 255),
		PIXEL(4, 0, 0, 50),
		PIXEL(5, 0, 0, 50),
		PIXEL(6, 0, 0, 50),
		PIXEL(7, 0, 0, 50),
		PIXEL(8, 0, 0, 50),
		PIXEL(9, 0, 0, 50),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 0, 0, 50),
		PIXEL(22, 0, 0, 50),
		PIXEL(23, 0, 0, 50),
		PIXEL(24, 0, 0, 50),
		PIXEL(25, 0, 0, 50),
		PIXEL(26, 0, 0, 50),
		PIXEL(27, 213, 255, 255)
	),
	FRAME(
		27,
		PIXEL(2, 213, 255, 255),
		PIXEL(3, 0, 0, 50),
		PIXEL(4, 0, 0, 50),
		PIXEL(5, 0, 0, 50),
		PIXEL(6, 0, 0, 50),
		PIXEL(7, 0, 0, 50),
		PIXEL(8, 0, 0, 50),
		PIXEL(9, 0, 0, 50),
		PIXEL(10, 0, 0, 50),
		PIXEL(11, 0, 0, 50),
		PIXEL(12, 0, 0, 50),
		PIXEL(13, 0, 0, 50),
		PIXEL(14, 0, 0, 50),
		PIXEL(15, 0, 0, 50),
		PIXEL(16, 0, 0, 50),
		PIXEL(17, 0, 0, 50),
		PIXEL(18, 0, 0, 50),
		PIXEL(19, 0, 0, 50),
		PIXEL(20, 0, 0, 50),
		PIXEL(21, 0, 0, 50),
		PIXEL(22, 0, 0, 50),
		PIXEL(23, 0, 0, 50),
		PIXEL(24, 0, 0, 50),
		PIXEL(25, 0, 0, 50),
		PIXEL(26, 0, 0, 50),
		PIXEL(27, 0, 0, 50),
		PIXEL(28, 213, 255, 255)
	)
};

int val;
bool blinkState = true;
volatile unsigned long blinkTime = 0; 
volatile unsigned long currentTime; 
bool DRLAccesa = true;

void setup() {
	Serial.begin(9600);

  	pinMode(5, INPUT);

	lxDRL.initialize(&onAnimationEnd_LX);
	//rxDRL.initialize();

	lxDRL.setupAnimation(16, startup, STARTUP_FRAMES, 60);
	lxDRL.startAnimation(16);

}

void onAnimationEnd_LX(int animationId) {
	Serial.print("LX Animation ");
	Serial.print(animationId);
	Serial.println(" ended");

	switch(animationId) {
		case 16: { //startup
			lxDRL.setupAnimation(17, blink, BLINK_FRAMES, 30);
			lxDRL.showDRL();
			DRLAccesa = true;
			//lxDRL.startAnimation(17);
			break;
		}
	}
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
			lxDRL.startAnimation(17);
		} else if(val == HIGH && blinkState == true) {
			blinkState = false;
			DRLAccesa = false;
			//Serial.println("SPENTO");
			//blinkTime = currentTime;
			//lxDRL.stopAnimation();
		}
  	}

  	if(currentTime - blinkTime > BLINK_FRAMES * 40 && DRLAccesa == false && val == HIGH) {
  		//Serial.println("FERMO DA TROPPO");
  		DRLAccesa = true;
  		lxDRL.reset();
  		lxDRL.showDRL();
  	}
	

	/* 
	 * lxDRL animation
	 */
	lxDRL.render();
}