#include "darts.h"

namespace darts
{

  int score(float x, float y)
  {
    float sq_distance = (x * x) + (y * y);
    if (sq_distance <= 1.0)
      return 10;
    else if (sq_distance <= 5.0 * 5.0)
      return 5;
    else if (sq_distance <= 10.0 * 10.0)
      return 1;
    else
      return 0;
  }
} // namespace darts
