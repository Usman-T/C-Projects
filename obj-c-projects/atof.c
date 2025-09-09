#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

double atof(char s[]) {
  double val, power;
  int i, sign;

  power = 1.0;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    ++i;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.') {
    i++;
    for (; isdigit(s[i]); ++i) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
    }
  }

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    int expSign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;

    int exp = 0;
    for (; isdigit(s[i]); i++)
      exp = 10 * exp + (s[i] - '0');

    power *= pow(10, exp * expSign);
  }

  return sign * val / power;
}

int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

int main() {
  double sum, atof(char[]);
  char line[MAXLINE];
  int getLine(char line[], int max);

  sum = 0;
  while (getLine(line, MAXLINE) > 0) {
    printf("\t%g\n", sum += atof(line));
  }

  return 0;
}
