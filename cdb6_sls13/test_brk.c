#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

extern int
main()
{
	int *dummy, i;

	TracePrintf(0, "Starting init program\n");
	TracePrintf(0, "PID: %d\n", GetPid());
	TracePrintf(0, "Attempting to delay for %d clock_ticks\n", 3);
	Delay(3);

	TracePrintf(0, "Attempting to delay for %d clock_ticks\n", 3);
	Delay(3);

	dummy = malloc(32 * sizeof(int));
	while (dummy != NULL) {
		TracePrintf(2, "Successful malloc call in init!\n");
		TracePrintf(2, "    dummy ptr is: %x, attempting to access\n",
		    dummy);
		for (i = 0; i < 32; i++) {
			dummy[i] = 0;
		}
		TracePrintf(2, "    Access check finished\n");

		dummy = malloc(32 * sizeof(int));
	}

	return(0);
}
