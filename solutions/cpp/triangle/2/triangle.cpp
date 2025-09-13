#include "triangle.h"

namespace triangle
{

  triangle::flavor kind(double a, double b, double c)
  {
    if (!(a + b > c && a + c > b && b + c > a) || !(a > 0 && b > 0 && c > 0))
      throw std::domain_error("Invalid triangle bitch");

    if (a == b && b == c)
      return triangle::flavor::equilateral;
    else if (a != b && b != c && a != c)
      return triangle::flavor::scalene;
    else
      return triangle::flavor::isosceles;
  }
} // namespace triangle
