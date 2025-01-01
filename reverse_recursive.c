#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int limit);
void reverse(char s[]);

int main() {
  char line[MAXLINE];

  while (getLine(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

int i = 0;
int j = 0;

void reverse(char s[]) {
  if (s[i] != '\0') {
    int c = s[i++];
    reverse(s);
    s[j++] = c;
  }

  if (s[j] == '\0') {
    i = 0;
    j = 0;
  }
}
