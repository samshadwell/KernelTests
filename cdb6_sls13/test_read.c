#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Reads input from the 0th terminal 3 characters at a time, printing them out
 * to the logfile.
 *
 * Expected Output:
 *   Everything that you type in is echo-ed out out up to 3 characters at a time
 *   dependent on newlines. Two processes are reading from it, so sometimes the
 *   reads may appear out of order.
 *
 *   You'll have to kill it yourself with Ctrl-C
 *
 * Requires:
 *   Fork(), TtyRead()
 */
extern int
main()
{
	int num_read;
	char *buf = malloc(sizeof(char) * 4);
	buf[3] = '\0';
	TracePrintf(0, "Starting test_read program\n");
	TracePrintf(0, "PID: %d\n", GetPid());
	
	Fork();
	while(1){
		num_read = TtyRead(0, (void *)buf, 3);
		buf[num_read] = '\0';
		TracePrintf(0, "Process %d read : %s\n", GetPid(), buf);
	}

	return(0);
}
