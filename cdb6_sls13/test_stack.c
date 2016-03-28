#include <stdlib.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

static void recursive_count(int i);

/**
 * Recursively calls itself, growing process stack until stack cannot be grown.
 *
 * Should see a ton of prints of numbers being incremented, along with logs that
 * the process Stack is being grown, eventually followed by a kernel memory
 * error that nothing is mapped to a given address (indicating the stack cannot
 * grow any more).
 *
 * Requires:
 *   The TRAP_MEMORY handler is implemented to grow the user stack
 */
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
