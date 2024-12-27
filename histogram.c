#include <stdio.h>

#define BUFFER 1000
#define IN  1
#define OUT 0

int main() 
{
  int c, i, wl, max, state;
  int words[BUFFER];
  
  state = OUT;
  wl = max = 0;

  for (i = 0; i <= BUFFER; ++i)
    words[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        ++words[wl];
        if (wl > max) 
          max = wl;
        wl = 0;
      }

      state = OUT;
    } else {
      if (state == OUT) {
        state = IN;
        wl = 1;
      } else {
        ++wl;
      }
    }
  }

  if (state == IN) {
    ++words[wl];
    if (wl > max) 
      max = wl;
    wl = 0;
  }

  putchar('\n');
  
  for (i = 0; i <= max; ++i) {
    printf("words of %2d length --- %2d\n", i, words[i]);
  }

  return 0;
} 
