#include <stdio.h>

#define BUFFER 1000
#define WRAP 30

int getLine(char line[]);
void wrap(char input[], char wrapped[]);

int main() {
  int len;
  char line[BUFFER];
  char output[BUFFER];

  while ((len = getLine(line)) > 0) {
    wrap(line, output);
    printf("%s", output);
  }

  return 0;
}

void wrap(char input[], char wrapped[]) {
  int i, w, lineLen;

  i = w = lineLen = 0;
  while (input[i] != '\0') {
    if (lineLen >= WRAP || input[i] == '\n') {
      wrapped[w++] = '\n';
      lineLen = 0;
      if (input[i] == '\n')
        i++;
    } else {
      wrapped[w++] = input[i++];
      lineLen++;
    }
  }

  wrapped[w] = '\0';
}

int getLine(char line[]) {
  int i;
  char c;

  for (i = 0; i < BUFFER - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}
