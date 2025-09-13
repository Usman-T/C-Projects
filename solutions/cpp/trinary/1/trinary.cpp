#include "trinary.h"

namespace trinary
{
  int to_decimal(std::string str)
  {
    int final{0};
    long unsigned power{str.length() - 1};

    for (long unsigned i{0}; i < str.length(); ++i)
    {
      if (!(str[i] >= '0' && str[i] <= '2'))
        return 0;

      final += (str[i] - '0') * pow(3, power);
      power--;
    }

    return final;
  }
} // namespace trinary
