#include <stdio.h>

#define BUFFER 1000

void escape(char s[], char t[]);
void get_line();

int main () {
  char s[BUFFER];
  char t[BUFFER];
  
  getLine(s, BUFFER);
  printf("%s", s);

  escape(s, t);
  printf("%s\n", t);

  return 0;
}

void escape(char dest[], char src[])
{
  int i, j;
  for (i = j = 0; src[i] != '\0'; ++i, ++j)
  {
    switch (src[i])
    {
    case '\a':
      dest[j++] = '\\';
      dest[j] = 'a';
      break;

    case '\b':
      dest[j++] = '\\';
      dest[j] = 'b';
      break;

    case '\f':
      dest[j++] = '\\';
      dest[j] = 'f';
      break;

    case '\n':
      dest[j++] = '\\';
      dest[j] = 'n';
      break;

    case '\r':
      dest[j++] = '\\';
      dest[j] = 'r';
      break;

    case '\t':
      dest[j++] = '\\';
      dest[j] = 't';
      break;

    case '\v':
      dest[j++] = '\\';
      dest[j] = 'v';
      break;

    case '\\':
      dest[j++] = '\\';
      dest[j] = '\\';
      break;

    case '\?':
      dest[j++] = '\\';
      dest[j] = '?';
      break;

    case '\'':
      dest[j++] = '\\';
      dest[j] = '\'';
      break;

    case '\"':
      dest[j++] = '\\';
      dest[j] = '"';
      break;

    default:
      dest[j] = src[i];
      break;
    }
  }

  if (src[i] == '\0')
  {
    dest[j] = src[i];
  }
}

void getLine(char s[], int limit) {
  int i, c;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i )    
     s[i] = c;

  if (c == '\n') 
    s[i++] = c;  

  s[i] = '\0';
  return i;
}
