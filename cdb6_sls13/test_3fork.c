#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

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
