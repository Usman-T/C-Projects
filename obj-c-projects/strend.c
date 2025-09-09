#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
  int sl = strlen(s);
  int tl = strlen(t);

  s += sl - 1;
  t += tl - 1;

  while (tl && (*s-- == *t--))
    --tl;

  if (tl)
    return 0;

  return 1;
}

int main() {
  char s[100] = "would";
  char *t = "gg";

  strend(s, t) ? printf("found string at the end\n")
               : printf("no string at the end\n");
}
