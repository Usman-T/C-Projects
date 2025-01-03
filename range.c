#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);
  printf("Range of unsigned int: 0 to %u\n", UINT_MAX);
  printf("Range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("Range of short: %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("Range of long: %ld to %ld\n", LONG_MIN, LONG_MAX);

  printf("Range of float: %e to %e\n", FLT_MIN, FLT_MAX);
  printf("Range of double: %e to %e\n", DBL_MIN, DBL_MAX);
  printf("Range of long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);

  return 0;
}
