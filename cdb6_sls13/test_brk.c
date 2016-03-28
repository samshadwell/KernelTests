#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Output:
 *   A bunch of printouts of "Successful malloc call in init" followed by some
 *   memory access checks. Then will get to point where malloc would have to
 *   overwrite the stack, and returns NULL.
 *
 *   After NULL return program exits.
 *
 * Tests:
 *   Brk, exit (although the Brk part isn't really dependent on Exit being
 *   implemented
 */
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
