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

  triangle::flavor kind(double, double, double);
} // namespace triangle
