#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Forks a child process which then goes and calls Exec() and runs another
 * process. The parent returns.
 *
 * Expected Output:
 *   Will print a starting message, then either parent or child prints. If the
 *   child executes first out of the fork, then the output of the exec-ed file
 *   is output.
 *   Should see calls to exit from both processes
 *
 * Requires:
 *   Fork, Exec, Exit
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
