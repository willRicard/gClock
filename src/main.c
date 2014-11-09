#include "gclock.h"
#include <signal.h>

static pthread_t pids[3];

void quit() {
	resetPins();
	printf("Exiting.\n");
	exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[]) {
	struct gClock data;
	pinSetup();
	pthread_create(&pids[0], NULL, threadWrite, &data);
	pthread_create(&pids[1], NULL, threadConfig, &data);
	pthread_create(&pids[2], NULL, threadAlarm, &data);
	signal(SIGINT, quit);
	signal(SIGKILL, quit);
	pthread_join(pids[0], NULL);
	return EXIT_SUCCESS;
}
