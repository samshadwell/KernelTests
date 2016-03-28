#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

extern int
main()
{
	char *buf = "asd";

	TracePrintf(0, "Starting test_read program\n");
	TracePrintf(0, "PID: %d\n", GetPid());
	
	Fork();
	while(1){
		TtyRead(0, (void *)buf, 3);
		TracePrintf(0, "%s\n", buf);
	}

	return(0);
}
