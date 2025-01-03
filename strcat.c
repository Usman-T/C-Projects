#include <stdio.h>

void strcate(char *s, char *t) {

  for (; *s != '\0'; s++)
    ;

  while (*s++ = *t++)
    ;
}

int main() {
  char s[100] = "hello";
  char *t = " damn bro world";

  strcate(s, t);
  printf("%s\n", s);
}
