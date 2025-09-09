
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]) {
  int i = 0;
  int sign = n;

  if (n < 0) {
    n = -n;
  }

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';

  int j;
  for (j = 0; j < i / 2; j++) {
    char temp = s[j];
    s[j] = s[i - j - 1];
    s[i - j - 1] = temp;
  }
}

int main() {
  char str[20];

  itoa(-1234, str);
  printf("String representation: %s\n", str);

  return 0;
}
