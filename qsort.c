#include <stdio.h>
#include <string.h>

void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);

  last = left; /* last possible pos for pivot */

  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[last]) > 0)
      swap(v, ++last, right);

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
