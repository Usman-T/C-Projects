#include <stdio.h>

#define BUFFER 1000

int lower(int c);

int main() {
  char c;

  while ((c = getchar()) != EOF) {
    c = lower(c);
    putchar(c);
  }
}

int lower(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
