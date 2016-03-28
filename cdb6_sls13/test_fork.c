#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

extern int
main()
{
	char *filename = "test_exec";
	char *argvec[] = { "Hello", "I'm", "test", "args", NULL};

	TracePrintf(0, "Starting forktest program\n");
	TracePrintf(0, "PID: %d\n", GetPid());

	if (Fork()) {
		TracePrintf(0, "I'm the parent, PID: %d\n", GetPid());
	} else {
		TracePrintf(0, "I'm the child, PID: %d\n", GetPid());
		Exec(filename, argvec);
	}

	return(0);
}
