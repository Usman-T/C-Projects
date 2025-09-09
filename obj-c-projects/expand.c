#include <stdio.h>
#include <string.h>

#define BUFFER 1000

void expand(char s1[], char s2[]);

int main() {
  char s1[BUFFER] = "-0-9A-F-";
  char s2[BUFFER];

  expand(s1, s2);
  printf("%s\n", s2);
}

void expand(char s1[], char s2[]) {
  int min, max, i, j;
  j = 0;

  for (i = 0; s1[i] != '\0'; ++i) {
    if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0') {
      min = s1[i - 1];
      max = s1[i + 1];

      if (min < max) {
        for (int c = min + 1; c <= max; ++c) {
          s2[j++] = c;
        }
      } else {
        s2[j++] = '-';
      }
      ++i;
    } else {
      s2[j++] = s1[i];
    }
  }

  s2[j] = '\0';
}
