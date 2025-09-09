#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() { return 0; }

int binsearch(int x, int v[], int n) {
  int high, low, mid;

  high = n - 1;
  low = 0;

  while (low <= high) {
    mid = (high + low) / 2;

    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  if (x == v[low - 1])
    return low - 1;

  return -1;
}
