#include <comp421/yalnix.h>
#include <comp421/hardware.h>

int main() {
  int x = 0;
  if (Fork() == 0) {
    while (1) {
      x++;
    }
  } else {
    while (1) {
      x--;
    }
  }
}
