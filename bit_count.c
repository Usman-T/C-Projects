#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned a = 12;

  printf("%d", bitcount(a));
  return 0;
}

int bitcount(unsigned x) {
  int b = 0;

  while (x != 0) {
    x &= (x - 1);
    ++b;
  }

  return b;
}
