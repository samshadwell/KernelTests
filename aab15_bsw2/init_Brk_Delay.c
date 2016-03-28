#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  int i = 0;
  char *str = malloc(sizeof(char) * 100);
  while(i < 11) {
    Delay(4);
    str[i] = 'a' + i;
    str[i + 1] = '\0';
    TracePrintf(-1, "Pid: %d, i: %d, str: %s\n", GetPid(), i, str);
    malloc(sizeof(uintptr_t) * 200);
    i++;
  }
  Brk((void *)(500 * PAGESIZE));
  Brk((void *)(450 * PAGESIZE));
  Exit(0);
}
