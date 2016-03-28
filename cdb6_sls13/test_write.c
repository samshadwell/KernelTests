#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/*
 * Forks into 4 processes, then each process writes into one of the 4 terminals
 * the string 'abc' repeatedly until the process is killed
 *
 * Expected output:
 *   'abc\n' printed to each of the terminals repeatedly until all you kill the
 *   process
 *
 * Requires:
 *   Fork(), TtyWrite()
 */
extern int
main()
{
	char *buf = malloc(sizeof(char) * 5);
	
	buf[0] = 'a';
	buf[1] = 'b';
	buf[2] = 'c';
	buf[3] = '\n';
	buf[4] = '\0';

	TracePrintf(0, "Starting test_read program\n");
	TracePrintf(0, "PID: %d\n", GetPid());
	
	Fork();
	Fork();
	while(1){
		TtyWrite(GetPid()%4, buf, 4);
	}

	return(0);
}
