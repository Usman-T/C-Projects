#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main() {
  unsigned a = 42;
  int b = 7;
  int c = 10;

  printf("%d", getbits(a, b, c));
  return 0;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p - n + 1) & ~(~0 << n));
}
