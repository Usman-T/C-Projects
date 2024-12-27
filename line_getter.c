#include <stdio.h>

#define MAXLINE 1000

/* rewrite getLine function without using conditional operators */

int getLine(char line[], int lim);

int main() {
  char line[MAXLINE];

  while (getLine(line, MAXLINE) > 0) {
    printf("%s \n", line);
  }

  return 0;
}

int getLine(char line[], int lim) {
  int i, c;

  i = 0;
  while (i < lim - 1) {
    c = getchar();

    if (c == '\n')
      break;
    else if (c == EOF)
      break;
    else {
      line[i] = c;
      ++i;
    }
  }

  line[i++] = '\0';
}
