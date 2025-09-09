/* htoi with standard functions */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define BUFFER 1000

int htoi(char s[]);
int getLine(char s[], int lim);

int main() {
  char hexa_str[BUFFER];
  int decimalVal;

  while (getLine(hexa_str, BUFFER) > 0) {
    decimalVal = htoi(hexa_str);
    if (decimalVal == -1)
      printf("Invalid format for hexadecimal\n");
    else
      printf("hex: %s -> decimal: %d\n", hexa_str, decimalVal);
  }

  return 0;
}

int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

int htoi(char s[]) {
  int i, n, result, tmp;

  i = result = 0;

  n = strlen(s);
  --n;

  while (i < n) {
    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
      i += 2;
    }

    int tmp = tolower(s[i]);

    if (isdigit(tmp))
      tmp -= 48; /* '0' means 48 */
    else if (isalpha(tmp) && tmp <= 'f')
      tmp = tmp - 'a' + 10;
    else
      return -1;

    result += tmp * (int)pow(16, n - i - 1);

    ++i;
  }

  return result;
}
