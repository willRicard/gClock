#include "gclock.h"

void writeDigit(int digit, int pin) {
	digitalWrite(pin, LOW);
	if (digit == 0) {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_C, HIGH);
		digitalWrite(SEG_D, HIGH);
		digitalWrite(SEG_E, HIGH);
		digitalWrite(SEG_F, HIGH);
	} else if (digit == 1) {
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_C, HIGH);
	} else if (digit == 2) {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_G, HIGH);
		digitalWrite(SEG_E, HIGH);
		digitalWrite(SEG_D, HIGH);
	} else if (digit == 3) {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_C, HIGH);
		digitalWrite(SEG_D, HIGH);
		digitalWrite(SEG_G, HIGH);
	} else if (digit == 4) {
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_C, HIGH);
		digitalWrite(SEG_F, HIGH);
		digitalWrite(SEG_G, HIGH);
	} else if (digit == 5) {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_F, HIGH);
		digitalWrite(SEG_G, HIGH);
		digitalWrite(SEG_C, HIGH);
		digitalWrite(SEG_D, HIGH);
	} else if (digit == 6) {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_C, HIGH);
		digitalWrite(SEG_D, HIGH);
		digitalWrite(SEG_E, HIGH);
		digitalWrite(SEG_F, HIGH);
	} else if (digit == 7) {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_C, HIGH);
	} else if (digit == 8) {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_C, HIGH);
		digitalWrite(SEG_D, HIGH);
		digitalWrite(SEG_E, HIGH);
		digitalWrite(SEG_F, HIGH);
		digitalWrite(SEG_G, HIGH);
	} else {
		digitalWrite(SEG_A, HIGH);
		digitalWrite(SEG_B, HIGH);
		digitalWrite(SEG_C, HIGH);
		digitalWrite(SEG_F, HIGH);
		digitalWrite(SEG_G, HIGH);
		digitalWrite(SEG_D, HIGH);
	}
	
	if (pin == PIN_D2) {
		digitalWrite(SEG_DP, HIGH);
	}
}

void* threadWrite(void* pdata) {
	struct gClock *data = pdata;
	while (1) {
		resetPins();
		time(&data->time);
		struct tm *t = localtime(&data->time);
		int d1 = t->tm_hour	/ 10;
		int d2 = t->tm_hour	% 10;
		int d3 = t->tm_min	/ 10;
		int d4 = t->tm_min	% 10;
		
		resetPins();
		writeDigit(d1, PIN_D1);
		delay(DELAY_WRITE);
		resetPins();
		writeDigit(d2, PIN_D2);
		delay(DELAY_WRITE);
		resetPins();
		writeDigit(d3, PIN_D3);
		delay(DELAY_WRITE);
		resetPins();
		writeDigit(d4, PIN_D4);
		delay(DELAY_WRITE);
	}
	pthread_exit(NULL);
}

void pinSetup() {
	wiringPiSetup();
	
	pinMode(PIN_D1, OUTPUT);
	pinMode(PIN_D2, OUTPUT);
	pinMode(PIN_D3, OUTPUT);
	pinMode(PIN_D4, OUTPUT);
	
	pinMode(SEG_A, OUTPUT);
	pinMode(SEG_B, OUTPUT);
	pinMode(SEG_C, OUTPUT);
	pinMode(SEG_D, OUTPUT);
	pinMode(SEG_E, OUTPUT);
	pinMode(SEG_F, OUTPUT);
	pinMode(SEG_G, OUTPUT);
	pinMode(SEG_DP, OUTPUT);
	
	resetPins();
}

void resetPins() {
	digitalWrite(PIN_D1, HIGH);
	digitalWrite(PIN_D2, HIGH);
	digitalWrite(PIN_D3, HIGH);
	digitalWrite(PIN_D4, HIGH);
	
	digitalWrite(SEG_A, LOW);
	digitalWrite(SEG_B, LOW);
	digitalWrite(SEG_C, LOW);
	digitalWrite(SEG_D, LOW);
	digitalWrite(SEG_E, LOW);
	digitalWrite(SEG_F, LOW);
	digitalWrite(SEG_G, LOW);
	digitalWrite(SEG_DP, LOW);
}
