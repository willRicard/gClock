#include "gclock.h"
#include <sys/types.h>
#include <sys/stat.h>

void* threadConfig(void* pdata) {
	struct gClock *data = pdata;
	struct stat s;
	time_t now, before;
	while (1) {
		int err = stat("/etc/gclock.conf", &s);
		if (err == 0) {
			now = s.st_mtime;
			if (now > before) {
				FILE* f = fopen("Config", "r");
				int h = 14, m = 6;
				fscanf(f, "%d:%d", &h, &m);
				data->alarm.h = h;
				data->alarm.m = m;
				fclose(f);
				before = now;
			}
		}
		sleep(DELAY_CHECK_CONFIG_UPDATE);
	}
	pthread_exit(NULL);
}
