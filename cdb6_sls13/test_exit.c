#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Expected Output:
 *   Logging for your forking function, then a print from one of the forked
 *   processes, followed by logged calls to exit, followed by a print from the
 *   other forked process, followed by more logged calls to exit.
 *
 * Requires:
 *   Fork() and Exit()
extern int
main()
{
	if (Fork()) {
		TracePrintf(0, "I'm the parent, PID: %d\n", GetPid());
		return(0);
	} else {
		TracePrintf(0, "I'm the child, PID: %d\n", GetPid());
		return(0);
	}
}
