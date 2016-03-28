#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

/**
 * Tests exec by calling exec for another file.
 *
 * You'll have to move the binary of the file being exec-ed into the same
 * directory in which the yalnix binary lives.
 *
 * Expected Output:
 *   Prints `Calling exec` before executing the other file. That file's output
 *   will then be shown.
 *
 *   If using our `test_exec`, just prints out the arguments provided to the
 *   new process, defined on line 26
 *
 * Tests:
 *   Exec, exit. Exit isn't necessary to see the exec output, though
 */
extern int
main()
{
	char *filename = "test_exec";
	char *argvec[5] = { "We're", "some", "test", "args", NULL };

	TracePrintf(0, "Calling exec\n");
	Exec(filename, argvec);

	return(0);
}
