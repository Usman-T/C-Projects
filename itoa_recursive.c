#include <stdio.h>

int i = 0;

void itoa(int n, char s[]) {
  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }

  if (n / 10) {
    itoa(n / 10, s);
    s[i++] = n % 10 + '0';
  } else {
    s[i++] = n % 10 + '0';
    s[i] = '\0';
  }
}

int main() {
  char str[20];

  itoa(-12234, str);
  printf("String representation: %s\n", str);

  return 0;
}
