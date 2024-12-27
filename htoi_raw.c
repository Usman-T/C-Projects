/* htoi with custom functions */
#include <stdio.h>

#define BUFFER 1000

int htoi(char hex[]);
int getLine(char s[], int lim);
int power(int base, int pow);
int str_len(char s[]);
int lower(int c);
int is_digit(int c);
int is_alpha(int c);

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
    s[i] = '\0';
  }

  return i;
}

int htoi(char s[]) {
  int i, n, result, tmp;

  i = result = 0;

  n = str_len(s);

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i += 2;
  }

  while (i < n) {
    tmp = lower(s[i]);
    if (is_digit(tmp))
      tmp -= '0';
    else if (is_alpha(tmp) && tmp <= 'f')
      tmp = tmp - 'a' + 10;
    else
      return -1;

    result = result * 16 + tmp;

    ++i;
  }

  return result;
}

int power(int base, int pow) {
  int result = 1;
  for (int i = 0; i < pow; ++i) {
    result *= base;
  }
  return result;
}

int str_len(char s[]) {
  int i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}

int lower(int c) { return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; }

int is_digit(int c) { return (c >= '0' && c <= '9'); }

int is_alpha(int c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
