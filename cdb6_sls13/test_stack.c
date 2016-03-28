#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

static void recursive_count(int i);

extern int
main()
{
	TracePrintf(0, "Starting test_stack\n");
	recursive_count(0);

	return(0);
}

static void
recursive_count(int i)
{
	TracePrintf(0, "%d\n", i);
	recursive_count(i + 1);
}
