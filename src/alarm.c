#include "gclock.h"

void* threadAlarm(void* pdata) {
	struct gClock *data = pdata;
	while (1) {
		struct tm* now = localtime(&data->time);
		int h_now = now->tm_hour;
		int m_now = now->tm_min;
		int h_alarm = data->alarm.h;
		int m_alarm = data->alarm.m;
		if (h_alarm - h_now <= 0 && m_alarm - m_now <= 0) {
			//What @todo ? I don't know...
		}
		sleep(DELAY_CHECK_ALARM);
	}
	pthread_exit(NULL);
}
