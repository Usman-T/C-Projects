#include <stdio.h>

/* m and n, pow = m^n */
int power(int m, int n);

int main () {
  int i;

  for (i = 1; i < 10; ++i) 
    printf("2^%1d: %3d, -3^%1d: %3d\n", i, power(2, i), i, power(-3, i));

  return 0;
}

int power(int base, int n) {
  int p, i;
  
  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;

  return p;
}
