#include <stdio.h>
#include <string.h>

#define BUFFER 100

void itob(int n, char s[], int base);

int main() {
  char s[BUFFER];
  int n = 666555;
  int base = 16;

  itob(n, s, base);
  printf("%s", s);

  return 0;
}

void itob(int n, char s[], int base) {
  int i = 0, sign;
  char lookup[16] = "0123456789ABCDEF";

  if ((sign = n) < 0)
    n = -n;

  do {
    s[i++] = lookup[n % base];
  } while (n /= base);

  s[i] = '\0';

  int j, temp;
  for (i = 0, j = strlen(s) - 1; i <= j; i++, j--) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
