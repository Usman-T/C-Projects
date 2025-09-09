#include "raindrops.h"

namespace raindrops
{
  std::string convert(int number)
  {
    std::string stringToReturn;

    if (number % 3 == 0)
      stringToReturn += "Pling";
    if (number % 5 == 0)
      stringToReturn += "Plang";
    if (number % 7 == 0)
      stringToReturn += "Plong";

    if (stringToReturn.empty())
      stringToReturn = std::to_string(number);

    return stringToReturn;
  }
} // namespace raindrops
