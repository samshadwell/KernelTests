#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  int chdReturn, chdPid;
  // Fork, yo
  if (Fork() == 0) {
    // child
    return 1234;
  } else {
    // parent
    chdPid = Wait(&chdReturn);
    printf("Child process %d returned with %d\n", chdPid, chdReturn); 
  }
  return 0;
}
