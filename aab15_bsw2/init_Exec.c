#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  char **argvec = malloc(sizeof(char *) * 5);
  argvec[0] = "-t";
  argvec[1] = "-l";
  argvec[2] = "-d";
  argvec[3] = "-r";
  argvec[4] = NULL;
  TracePrintf(-1, "In process %d\n", GetPid());
  printf("In process %d\n", GetPid()); 
  
  if (Exec("listArgs", argvec) != 0) {
    TracePrintf(-1, "Exec failed to work :(\n");
    printf("Exec failed to work :(\n");
  } else {
    TracePrintf(-1, "Exec was 'sucessful', but since we're here, it still failed :(\n");
    printf("Exec was 'sucessful', but since we're here, it still failed :(\n");
  }
  return 0;
}
