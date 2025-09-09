#include <stdio.h>

unsigned setbits(unsigned x, unsigned y, int p, int n);

int main() {
  unsigned a = 10;
  int b = 4;
  int c = 2;
  unsigned d = 2;

  printf("%d", setbits(a, d, b, c));
  return 0;
}

unsigned setbits(unsigned x, unsigned y, int p, int n) {
  return (x & ~((1 << n) << (p + 1 - n))) | (y & ((1 << n) - 1) << (p - n + 1));
}
