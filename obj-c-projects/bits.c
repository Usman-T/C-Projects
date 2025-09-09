#include <stdio.h>

int main() {

  int x = 1; // 00000100
  int y = 2; // 00000010

  printf("x = %d, y = %d\n", x, y);
  printf("x & y = %d\n", x & y);
  printf("x | y = %d\n", x | y);
  printf("x ^ y = %d\n", x ^ y);
  printf("x >> y = %d\n", x >> y);
  printf("x << y = %d\n", x << y);

  printf("~4: %d", ~4U);

  return 0;
}
