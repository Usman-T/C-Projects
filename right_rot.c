#include <stdio.h>

int rightrot(int a, int b);

int main() {
  int a = 16;
  int b = 4;

  printf("%d", rightrot(a, b));
  return 0;
}

int rightrot(int x, int n) {
  // generally: x >> n = x / 2^n
  return x >> n;
}
