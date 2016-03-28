#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  int numRead, len = TERMINAL_MAX_LINE, term = 1;
  uint8_t buf[TERMINAL_MAX_LINE];

  while (1) {
    numRead = TtyRead(term, buf, len);
    if (numRead < 0) {
      /* An error occurred while reading. Print error and exit the process. */
      TracePrintf(-1, "An error occurred while trying to read from the terminal\n");
      break;
    } else {
      TracePrintf(-1, "Read %d bytes from terminal %d\n", numRead,term);
    }
  }
  Exit(0);
} 
