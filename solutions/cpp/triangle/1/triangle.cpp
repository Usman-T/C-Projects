#include "triangle.h"

namespace triangle
{

  triangle::flavor kind(int a, int b, int c)
  {
    if (!(a + b > c && a + c > b && b + c > a))
      throw std::domain_error("Nah bitch");

    if (a == b && b == c && a == c)
      return triangle::flavor::equilateral;
    else if (a != b && b != c && a != c)
      return triangle::flavor::scalene;
    else
      return triangle::flavor::isosceles;
  }
} // namespace triangle
