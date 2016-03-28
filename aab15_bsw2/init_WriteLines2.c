#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main() {
  int term = 1;
  uint8_t *buf;
  char **argvec = malloc(sizeof(char *));

  /* Fork the second process. */
  if (Fork() == 0) {
    TracePrintf(-1, "Forking child process\n");

    argvec[0] = NULL;
    if (Exec("init_WriteLines", argvec) < 0) {
      TracePrintf(-1, "Could not execute init_WriteLines\n"); 
    }
  }

  while (1) {
    buf = (uint8_t *)"Writing from 2\n";
    TtyWrite(term, buf, strlen((char *)buf));
    TracePrintf(-1, "Wrote %d bytes to terminal %d\n", strlen((char *)buf), term);
  }
  Exit(0);
} 
