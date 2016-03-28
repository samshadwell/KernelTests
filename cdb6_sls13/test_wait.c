#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

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
