#include "DRLBlinker.h"

#define LEDS_PER_STRIP 31


DRLBlinker<7, LEDS_PER_STRIP> lxDRL("lxDRL", CHSV(0, 0, 40));
DRLBlinker<8, LEDS_PER_STRIP> rxDRL("rxDRL", CHSV(0, 0, 40));


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


#define STARTUP_FRAMES 20
Frame startup[STARTUP_FRAMES] = {
	FRAME(
		2,
		ALL_RESET,
		PIXEL(15, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(14, 213, 255, 255),
		PIXEL(16, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(13, 213, 255, 255),
		PIXEL(17, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(12, 213, 255, 255),
		PIXEL(18, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(11, 213, 255, 255),
		PIXEL(19, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(10, 213, 255, 255),
		PIXEL(20, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(9, 213, 255, 255),
		PIXEL(21, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(8, 213, 255, 255),
		PIXEL(22, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(7, 213, 255, 255),
		PIXEL(23, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(6, 213, 255, 255),
		PIXEL(24, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(5, 213, 255, 255),
		PIXEL(25, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(4, 213, 255, 255),
		PIXEL(26, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(3, 213, 255, 255),
		PIXEL(27, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(2, 213, 255, 255),
		PIXEL(28, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(1, 213, 255, 255),
		PIXEL(29, 213, 255, 255)
	),
	FRAME(
		3,
		ALL_RESET,
		PIXEL(0, 213, 255, 255),
		PIXEL(30, 213, 255, 255)
	),
	FRAME(
		2,
		PIXEL(0, 213, 255, 255),
		PIXEL(30, 213, 255, 255)
	),
	FRAME(
		2,
		PIXEL(0, 213, 255, 255),
		PIXEL(30, 213, 255, 255)
	),
	FRAME(
		2,
		PIXEL(1001, 0, 0, 0),
		PIXEL(1031, 0, 0, 0)
	),
	FRAME(
		2,
		PIXEL(2001, 0, 0, 0),
		PIXEL(2031, 0, 0, 0)
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
	lxDRL.setupAnimation(16, startup, STARTUP_FRAMES, 60);
	lxDRL.startAnimation(16);

	rxDRL.initialize(&onAnimationEnd_RX);
	rxDRL.setupAnimation(16, startup, STARTUP_FRAMES, 60);
	rxDRL.startAnimation(16);
}

void onAnimationEnd_LX(int animationId) {
	Serial.print("LX Animation ");
	Serial.print(animationId);
	Serial.println(" ended");

	switch(animationId) {
		case 16: { //startup
			//lxDRL.setupAnimation(16, startup, STARTUP_FRAMES, 60);
			//lxDRL.startAnimation(16);
			lxDRL.setupAnimation(17, blink, BLINK_FRAMES, 30);
			lxDRL.startAnimation(17);
			/*lxDRL.showDRL();
			DRLAccesa = true;*/
			break;
		}
		case 17: {
			lxDRL.setupAnimation(16, startup, STARTUP_FRAMES, 60);
			lxDRL.startAnimation(16);
			break;
		}
	}
}

void onAnimationEnd_RX(int animationId) {
	Serial.print("RX Animation ");
	Serial.print(animationId);
	Serial.println(" ended");

	switch(animationId) {
		case 16: { //startup
			rxDRL.setupAnimation(17, blink, BLINK_FRAMES, 30);
			rxDRL.showDRL();
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
			rxDRL.startAnimation(17);
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
  		/*lxDRL.reset();
  		lxDRL.showDRL();

  		rxDRL.reset();
  		rxDRL.showDRL();*/
  	}
	

	/* 
	 * lxDRL animation
	 */
	lxDRL.render();

	/* 
	 * rxDRL animation
	 */
	//rxDRL.render();
}