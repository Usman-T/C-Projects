#include <stdio.h>

#define TABSIZE 20

/* Enter an input string with tabs where each tab takes you to the next TABSTOP
 * instead of the 8 spaced tab. */

int main() {
  char c;
  int i, col;

  while ((c = getchar()) != EOF) {
    ++col;
    if (c == '\t') {
      col = TABSIZE;

      while (col) {
        putchar(' ');
        --col;
      }
    } else
      putchar(c);
  }

  return 0;
}
