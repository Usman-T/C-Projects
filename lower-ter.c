#include <stdio.h>

int lower(int c);

int main() {
  char c;

  while ((c = getchar()) != EOF) {
    c = lower(c);
    putchar(c);
  }

  return 0;
}

int lower(int c) { c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }
