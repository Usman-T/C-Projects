#include "darts.h"

namespace darts
{
  bool isPointInCircle(float x, float y, float r)
  {
    float squared_distance = (x * x) + (y * y);

    return squared_distance <= (r * r);
  }

  int score(float x, float y)
  {
    if (isPointInCircle(x, y, 1))
      return 10;
    if (isPointInCircle(x, y, 5))
      return 5;
    if (isPointInCircle(x, y, 10))
      return 1;
    else
      return 0;
  }
} // namespace darts
