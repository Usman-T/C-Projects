#define BUFFER 1000
#define EOF (-1)

int getchar_custom();
int htoi(char s[]);
int str_len(char s[]);
int power(int base, int exp);
int tolower_custom(int c);
int is_digit(int c);
int is_alpha(int c);
void print_string(char *str);
void print_number(int num);

int main() {
  char hexa_str[BUFFER];
  int decimalVal;

  while (1) {
    int i = 0;
    // Get input line
    while (1) {
      int c = getchar_custom();
      if (c == EOF || c == '\n')
        break;
      hexa_str[i++] = c;
    }
    hexa_str[i] = '\0'; // Null-terminate the string

    // Convert hex to decimal
    decimalVal = htoi(hexa_str);
    if (decimalVal == -1) {
      print_string("Invalid format for hexadecimal\n");
    } else {
      print_string("hex: ");
      print_string(hexa_str);
      print_string(" -> decimal: ");
      print_number(decimalVal);
      print_string("\n");
    }
  }

  return 0;
}

// Custom getchar using sys_read system call
int getchar_custom() {
  int c;
  __asm__ volatile("mov $0, %%rax;" // syscall number for sys_read
                   "mov $0, %%rdi;" // file descriptor 0 (stdin)
                   "mov %1, %%rsi;" // address of the character to be read
                   "mov $1, %%rdx;" // number of bytes to read (1 byte)
                   "syscall;"
                   : "=m"(c) // Output
                   : "r"(&c) // Input (address of 'c')
                   : "rax", "rdi", "rsi", "rdx");
  return (c == 0) ? EOF : c; // Return EOF if no input
}

// Custom function to print a string using sys_write
void print_string(char *str) {
  while (*str) {
    int c = *str;
    __asm__ volatile(
        "mov $1, %%rax;" // syscall number for sys_write
        "mov $1, %%rdi;" // file descriptor 1 (stdout)
        "mov %0, %%rsi;" // address of string to print
        "mov $1, %%rdx;" // number of bytes to write (1 byte per character)
        "syscall;"
        :
        : "r"(str)
        : "rax", "rdi", "rsi", "rdx");
    str++;
  }
}

// Custom function to print a number (int) as a string using sys_write
void print_number(int num) {
  char buffer[20];
  int i = 0;

  if (num == 0) {
    buffer[i++] = '0';
  } else {
    int is_negative = 0;
    if (num < 0) {
      is_negative = 1;
      num = -num;
    }

    while (num > 0) {
      buffer[i++] = num % 10 + '0';
      num /= 10;
    }

    if (is_negative) {
      buffer[i++] = '-';
    }

    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
      char temp = buffer[j];
      buffer[j] = buffer[i - j - 1];
      buffer[i - j - 1] = temp;
    }
  }

  buffer[i] = '\0';
  print_string(buffer);
}

int htoi(char s[]) {
  int i, n, result, tmp;

  i = result = 0;
  n = str_len(s);

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i += 2; // Skip the '0x' or '0X'
  }

  while (i < n) {
    tmp = tolower_custom(s[i]);
    if (is_digit(tmp))
      tmp -= '0';
    else if (is_alpha(tmp) && tmp <= 'f')
      tmp = tmp - 'a' + 10;
    else
      return -1; // Invalid character

    result = result * 16 + tmp;
    ++i;
  }

  return result;
}

int str_len(char s[]) {
  int i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}

int tolower_custom(int c) {
  return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

int is_digit(int c) { return (c >= '0' && c <= '9') ? 1 : 0; }

int is_alpha(int c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0;
}
