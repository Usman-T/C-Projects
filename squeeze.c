#include <stdio.h>

void squeeze(char string[], char remove[]);

int main() {
  char s1[] = "hello";
  char s2[] = "l";

  printf("s1 originally: \"%s\"\n", s1);
  squeeze(s1, s2);
  printf("s1 after: \"%s\"\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;
  int match;

  k = 0;
  for (i = 0; s1[i] != '\0'; ++i) {
    match = 0;
    for (j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        match = 1;
        break;
      }
    }

    if (!match) {
      s1[k++] = s1[i];
    }
  }

  s1[k] = '\0';
}
