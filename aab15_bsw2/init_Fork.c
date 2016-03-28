#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  int forkTimes = 0;
  while (1) {
    forkTimes++;
    if (Fork() == 0) {
      if (forkTimes > 6) {
        break;
      }
    } else {
      break;
    }
  }
  TracePrintf(-1, "Process %d done, forked %d times!\n", GetPid(), forkTimes);
  Exit(0);
} 
