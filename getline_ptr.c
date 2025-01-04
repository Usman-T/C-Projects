#include <stdio.h>

#define MAXLINE 1000

int getline_ptr(char *line, int lim) {
  int c;
  char *start = line;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *line++ = c;
  if (c == '\n')
    *line++ = c;

  *line = '\0';
  return line - start;
}

int main() {
  char line[MAXLINE];
  while (getline_ptr(line, MAXLINE) > 0)
    printf("%s", line);

  return 0;
}
