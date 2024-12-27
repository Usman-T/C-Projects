#include <stdio.h>
#define MAXLINE 10 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main () {
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    printf("%d: %s", len, line); 
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) { /* there was a line */
      printf("Longest length: %d\n", max);
      printf("Longest string: %s\n", longest);
  }

  return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim) {
  int c, i, counter;
  
  counter = 0;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
    counter++;
  }
  
  if (c == '\n') {
    s[counter] = c;
    counter++; 
  }

  s[counter] = '\0';

  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
