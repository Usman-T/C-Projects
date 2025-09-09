#include <stdio.h>
#include <string.h>

void strncpy_ptr(char *s, char *t, int n) {
  while ((*s++ = *t++) && n--)
    ;
}

void strncat_ptr(char *s, char *t, int n) {
  int sl = strlen(s);

  s += sl;
  while ((*s++ = *t++) && n--)
    ;
}

void strncmp_ptr(char *s, char *t, int n) {
  while (*s++ == *t++ && n--)
    if (*s == '\0')
      return 0;

  return *s - *t;
}

int main() {
  char s[100] = "hello";
  char *t = "would you help";

  strncpy_ptr(s, t, 8);
  printf("%s\n", s);

  strncat_ptr(s, t, 8);
  printf("%s\n", s);

  strncmp_ptr(s, t, 8);
  printf("%s\n", s);

  return 0;
}
