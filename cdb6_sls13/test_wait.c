#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Parent spawns a child then waits on it. Then attempts to wait on nonexistent
 * child process.
 *
 * Expected Output:
 *   Child will print message post-fork, and then return and call exit.
 *   Parent will reap that child and print its PID and exit status
 *   Parent will then wait on nonexistent child, and should print -1 twice
 *
 * Requires:
 *   Fork(), Wait(), Exit()
 */
extern int
main()
{
	int *status = malloc(sizeof(int)), child_pid;

	if (Fork()) {
		TracePrintf(0, "I'm the parent, PID: %d\n", GetPid());
		child_pid = Wait(status);
		TracePrintf(0, "  child %d exited with status: %d\n", child_pid,
		    status[0]);
		TracePrintf(0, "  expected status of:         %d\n", 15);

		child_pid = Wait(status);
		TracePrintf(0, "  child %d error? %d\n", child_pid, ERROR);
		return(0);
	} else {
		TracePrintf(0, "I'm the child, PID: %d\n", GetPid());
		return(15);
	}
}
