#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main() {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    printf("\nSorted lines:\n");
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input is too big");
    return 1;
  }
}

void swap(char *v[], int i, int j) {
  char *tmp;

  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  swap(v, last, left);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

int getLine(char line[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && ((c = getchar()) != EOF) && c != '\n')
    line[i++] = c;

  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';

  return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp > n) {
    allocp += n;
    return allocp - n;
  } else
    return NULL;
}

int readlines(char *lineptr[], int max) {
  int len, nlines;
  char *p;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0) {
    if (nlines >= max || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}
