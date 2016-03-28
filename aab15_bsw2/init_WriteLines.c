#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main() {
  int term = 1;
  uint8_t *buf;

  while (1) {
    buf = (uint8_t *)"Writing from 1\n";
    TtyWrite(term, buf, strlen((char *)buf));
    TracePrintf(-1, "Wrote %d bytes to terminal %d\n", strlen((char *)buf), term);
  }
  Exit(0);
} 
