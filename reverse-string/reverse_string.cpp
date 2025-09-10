#include "reverse_string.h"

namespace reverse_string
{
  std::string reverse_string(std::string str)
  {
    int end = str.length() - 1;
    std::string reversed_string;

    while (end >= 0)
      reversed_string += str[end--];

    return reversed_string;
  }
} // namespace reverse_string
