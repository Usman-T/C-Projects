#include "grains.h"
#include <iostream>

namespace grains
{

  long long unsigned square(int n)
  {
    long long unsigned grains_on_curr{1};

    for (int i{1}; i < n; ++i)
    {
      grains_on_curr *= 2;
    }

    return grains_on_curr;
  }

  long long unsigned total()
  {
    long long unsigned total_grains{0};

    for (int i{1}; i <= 64; ++i)
    {
      total_grains += square(i);
    }

    return total_grains;
  }

} // namespace grains
