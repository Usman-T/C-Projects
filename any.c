#include <stdio.h>

#define BUFFER 1000

int any(char s1[], char s2[]);

int main() {
  char s1[BUFFER] = "Hello World";
  char s2[BUFFER] = "e";
  int position;

  position = any(s1, s2);

  if (position != -1)
    printf("found char \'%c\' at position %d\n", s1[position], position);
  else
    printf("found no matching characters\n");

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }

  return -1;
}
