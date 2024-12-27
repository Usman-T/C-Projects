#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[], int lim);
void copy(char to[], char from[]);

int getLine(char s[], int lim) {
  int i;
  char c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while (from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
}

int main() {
  int max;
  int len;
  char longest[MAXLINE];
  char line[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {

    putchar('\"');
    for (int j = 0; j < len; ++j) {
      if (line[j] != '\n' && line[j] != '\t')
        putchar(line[j]);
      else
        continue;
    }

    printf("\" has %d characters\n", len);

    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("The longest line has %d characters.", max);
  }
}
