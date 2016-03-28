#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Expected behavior:
 *   Parent spawns 3 child processes then starts infinite looping.
 *
 *   Each child thread also gets into an infinite loop.
 *
 *   Should see your Kernel context switching between the 4 processes if
 *   that's something you're logging.
 *
 * Tests:
 *   Fork
 */

extern int
main()
{
	int i;
	char *argvec[] = { NULL };

	TracePrintf(0, "Starting init program\n");
	TracePrintf(0, "PID: %d\n", GetPid());

	for(i = 0; i < 3; i++){
		if(Fork() > 0) break;
	}

	while(1){
		Pause();
	}

	return(0);
}
