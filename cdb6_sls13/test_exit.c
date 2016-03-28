#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

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
