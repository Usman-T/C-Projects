#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define MAXVARS 26
#define VARGET 'a'
#define VARSET '_'

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);

void clear(void);
void duplicate(void);
void swap(void);

int sp = 0;
double val[MAXVAL];
char var = '0';

int main() {
  int type;
  double op2;
  char s[MAXOP];

  double vars[MAXVARS];
  int var_index = 0;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: dividing by zero\n");
      }
      break;
    case '%':
      op2 = pop();
      if (op2 <= 0) {
        printf("error: dividing by zero\n");
      } else {
        push((int)pop() % (int)op2);
      }
      break;
    case 't':
      if (sp > 0)
        printf("top: %g \n", val[sp - 1]);
      else
        printf("error: no stack found\n");
      break;
    case 'f':
      printf("first: %g\n", val[0]);
      break;
    case 'd':
      duplicate();
      break;
    case 'c':
      clear();
      break;
    case 's':
      swap();
      break;
    case '~':
      push(sin(pop()));
      break;
    case 'e':
      push(exp(pop()));
      break;
    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case VARSET:
      vars[var_index++] = pop();
      printf("variable %c: %.3f\n", 'a' + var_index - 1, vars[var_index - 1]);
      break;
    case VARGET:
      if (var - 'a' <= (var_index - 1)) {
        push(vars[var - 'a']);
      } else {
        printf("error: unknown variable\n");
      }
      break;
    case '\n':
      printf("result: %.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

void swap(void) {
  int temp;
  temp = val[sp - 1];
  val[sp - 1] = val[sp - 2];
  val[sp - 2] = temp;
}

void clear(void) {
  while (sp > 0)
    val[sp--] = 0;
  printf("cleared\n");
}

void duplicate(void) {
  if (sp > 0)
    val[sp++] = val[sp - 1];
  else
    printf("error: stack is empty\n");
}

void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack is empty\n");
    return 0.0;
  }
}

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (islower(c)) {
    var = c;
    return VARGET;
  }

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch() {
  if (bufp > 0)
    return buf[--bufp];
  else
    return getchar();
}

void ungetch(int c) {
  if (bufp > BUFSIZE - 1)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; ++i)
    ungetch(s[i]);
}
