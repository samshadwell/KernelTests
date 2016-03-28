#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Doesn't actually test anything on its own. Rather, this file is used as the
 * argument to `Exec` to test it.
 *
 * If run, this program prints the arguments passed to it.
 */
extern int
main(int argc, char **argv)
{
	int i;

	TracePrintf(0, "PID %d executing in exec_test\n", GetPid());
	for (i = 0; i < argc; i++) {
		TracePrintf(0, "argv[%d]: %s\n", i, argv[i]);
	}

	Exit(0);
}
