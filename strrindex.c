#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[10] = "l";

int main() {
  char line[MAXLINE];
  int found = 0;
  int t;

  while (getLine(line, MAXLINE) > 0) {
    if ((t = strrindex(line, pattern)) >= 0) {
      printf("%s\n", line);
      found++;
    }
    printf("t = %d\n", t);
  }

  return found;
}

int getLine(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

int strrindex(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = 0, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
    printf("i: %d, j: %d, k: %d\n", i, j, k);
  }
  return -1;
}
