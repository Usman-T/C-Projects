#pragma once
#include <stdexcept>

namespace triangle
{
  enum class flavor
  {
    equilateral,
    isosceles,
    scalene
  };

  triangle::flavor kind(int, int, int);
} // namespace triangle
