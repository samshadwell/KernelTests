#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * The proper behavior is to fork, parent passes flags: -p-r-n-t
 * child passes flags: -c-h-l-d
 * Both terminate normally.
 */
int main() {
  int forkResult;
  char **argvec = malloc(sizeof(char *) * 5);
  argvec[0] = "-t";
  argvec[1] = "-l";
  argvec[2] = "-d";
  argvec[3] = "-r";
  argvec[4] = NULL;
  TracePrintf(-1, "In process %d\n", GetPid());
  printf("In process %d\n", GetPid()); 
 
  forkResult = Fork(); 
  if (forkResult== 0) {
    // Child
    argvec[0] = "-c";
    argvec[1] = "-h";
    argvec[2] = "-l";
    argvec[3] = "-d";
    if (Exec("listArgs", argvec) != 0) {
      TracePrintf(-1, "Exec failed to work :(\n");
      printf("Exec failed to work :(\n");
      return -1;
    } else {
      TracePrintf(-1, "Exec was 'sucessful', but since we're here, it still failed :(\n");
      printf("Exec was 'sucessful', but since we're here, it still failed :(\n");
      return -1;
    }
  } else if (forkResult != -1) {
    // Parent
    argvec[0] = "-p";
    argvec[1] = "-r";
    argvec[2] = "-n";
    argvec[3] = "-t";
    if (Exec("listArgs", argvec) != 0) {
      TracePrintf(-1, "Exec failed to work :(\n");
      printf("Exec failed to work :(\n");
      return -1;
    } else {
      TracePrintf(-1, "Exec was 'sucessful', but since we're here, it still failed :(\n");
      printf("Exec was 'sucessful', but since we're here, it still failed :(\n");
      return -1;
    }
  } else {
    TracePrintf(-1, "Fork failed. :(\n");
    printf("Fork failed. :(\n");
  } 

  return (0);
}
