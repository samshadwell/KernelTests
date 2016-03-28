#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int i;
  TracePrintf(-1, "In process %d\n", GetPid());
  printf("In process %d\n", GetPid());
  
  TracePrintf(-1, "%d arguments passed in\n", argc);
  printf("%d arguments passed in\n", argc);
  for (i = 0; i < argc; i++) {
    TracePrintf(-1, "\targ %d is %s\n", i, argv[i]);
    printf("\targ %d is %s\n", i, argv[i]);
  }
  return 0;
}
