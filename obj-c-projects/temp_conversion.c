#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 30

float convert(float fahr);

int main() {
  float i;
 
  for (i = LOWER; i <= UPPER; i += STEP)
     printf("%3.1fF \t %6.1fC\n", i, convert(i));

  return 0;
}

float convert(float fahr) {
  float celsius = 0;
  celsius = (5.0 / 9.0) * (fahr - 32.0); 
  
  return celsius;
}
