#include <stdio.h>
#include <string.h>

#define MAXLINE 5000
#define MAXLEN 1000

char *lineptr[MAXLINE];

int readlines(char *lineptr[], int linelim);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getLine(char *, int);
char *alloc(int n);

int main() {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;

  } else {
    printf("error: input data is too large\n");
    return 1;
  }
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }

  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  printf("\nSorted lines:\n");
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else
    return NULL;
}

void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);

  last = left; /* last possible pos for pivot */

  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);

  swap(v, left, last);       /* restore pivot back */
  qsort(v, left, last - 1);  /* partition A (smaller elems) */
  qsort(v, last + 1, right); /* partition B (larger elems) */
}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}
