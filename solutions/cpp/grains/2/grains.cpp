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
    long long unsigned total_grains{1};
    long long unsigned curr{1};

    for (int i{2}; i <= 64; ++i)
    {
      curr *= 2;
      total_grains += curr;
    }

    return total_grains;
  }

} // namespace grains
