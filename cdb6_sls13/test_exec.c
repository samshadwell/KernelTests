#include <comp421/hardware.h>
#include <comp421/yalnix.h>

extern int
main(int argc, char **argv)
{
	int i;

	TracePrintf(0, "PID %d executing in exec_test\n", GetPid());
	for (i = 0; i < argc; i++) {
		TracePrintf(0, "argv[%d]: %s\n", i, argv[i]);
	}

	while (1) ;

	Exit(0);
}
