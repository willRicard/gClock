//@author Guillaume Ricard <guillaume.ricard@mail.com>
#ifndef INCLUDE_GCLOCK_H
#define INCLUDE_GCLOCK_H

	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <pthread.h>
	#include <wiringPi.h>
	
	enum Pin {		//7-segment display PIN
		SEG_A = 0,	//11
		SEG_B = 1,	//7
		SEG_C = 2,	//4
		SEG_D = 3,	//2
		SEG_E = 4,	//1
		SEG_F = 5,	//10
		SEG_G = 6,	//5
		SEG_DP = 7,	//3
		
		PIN_D1 = 8,	//12
		PIN_D2 = 9,	//9
		PIN_D3 = 10,	//8
		PIN_D4 = 11	//6
	};
	
	enum Delay {
		DELAY_WRITE			= 5,	//ms
		DELAY_CHECK_ALARM		= 30,	//s
		DELAY_CHECK_CONFIG_UPDATE	= 30	//s
	};
	
	struct Alarm {
		int h;
		int m;
	};
	
	struct gClock {
		struct Alarm alarm;
		time_t time;
	};
	
	//write.c
	void*	threadWrite(void*);
	void 	pinSetup();
	void	resetPins();
	//config.c
	void*	threadConfig(void*);
	//alarm.c
	void*	threadAlarm(void*);

#endif //INCLUDE_GCLOCK_H
