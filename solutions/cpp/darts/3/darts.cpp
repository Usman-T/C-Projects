#include "darts.h"

namespace darts
{

  int score(float x, float y)
  {
    float sq_distance = (x * x) + (y * y);
    if (sq_distance <= 1.0)
      return 10;
    else if (sq_distance <= 25.0)
      return 5;
    else if (sq_distance <= 100.0)
      return 1;
    else
      return 0;
  }
} // namespace darts
