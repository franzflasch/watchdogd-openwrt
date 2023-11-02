#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "wdog.h"

extern char *__progname;
extern int   __wdog_testmode;

#define DEBUG(fmt, args...)  if (dbg) printf("%s: " fmt "\n", __progname, ##args);
#define PERROR(fmt, args...) if (dbg) fprintf(stderr, "%s: " fmt ": %s\n", __progname, ##args, strerror(errno));

int main(int argc, char *argv[])
{
	int id, i, dbg = 0;
	unsigned int ack;

	if (argc >= 2 && !strncmp(argv[1], "-V", 2))
		dbg = 1;

	DEBUG("=> Checking connectivity with watchdogd ...");
	if (wdog_ping()) {
		PERROR("Failed connectivity check");
		return 1;
	}
	DEBUG("=> OK!");

	id = wdog_subscribe(NULL, 3000, &ack);
	if (id < 0) {
		perror("Failed connecting to wdog");
		return 1;
	}

	for (i = 0; i < 20; i++) {
		int enabled = 0;

		if (wdog_status(&enabled))
			PERROR("Failed reading wdog status");

		DEBUG("=> Kicking ack:%d ... (%sABLED)", ack, enabled ? "EN" : "DIS");
		if (wdog_kick2(id, &ack))
			PERROR("Failed kicking");
		sleep(2);

		/* Apx. halfway through, disable wdog ... */
		if (i == 8) {
			DEBUG("=> Verify that wdog can be disabled at runtime.");
			wdog_enable(0);

			/* Miss deadline */
			sleep(3);
		}

		/* Let program kick "in the air" for a few iterations, must work! */

		/* Later on ... re-enable */
		if (i == 14) {
			DEBUG("=> Re-enabling wdog ...");
			wdog_enable(1);
		}
	}

	DEBUG("=> Exiting ...");
	if (wdog_unsubscribe(id, ack)) {
		PERROR("Failed unsubscribe");
		return 1;
	}

	return 0;
}
