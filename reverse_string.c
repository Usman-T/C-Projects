#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[], int lim);
void reverse(char s[], char rev[], int len);

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

void reverse(char s[], char reversed[], int len) {
  int i;

  for (i = 0; i < len - 1; ++i) {
    reversed[i] = s[len - i - 2];
  }

  if (s[len - 1] == '\n') {
    reversed[++i] = '\n';
  }

  reversed[i] = '\0';
}

int main() {
  int len;
  char rev[MAXLINE];
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    reverse(line, rev, len);
    printf("%s", rev);
  }

  return 0;
}
