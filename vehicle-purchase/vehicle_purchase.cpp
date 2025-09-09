#include "vehicle_purchase.h"

namespace vehicle_purchase
{

  bool needs_license(std::string kind)
  {
    if (kind == "car" || kind == "truck")
      return true;
    return false;
  }

  std::string choose_vehicle(std::string option1, std::string option2)
  {
    std::string chosen_vehicle;

    if (option1 > option2)
      chosen_vehicle = option2;
    else
      chosen_vehicle = option1;

    return chosen_vehicle + " is clearly the better choice.";
  }

  // calculate_resell_price calculates how much a vehicle can resell for at a
  // certain age.
  double calculate_resell_price(double original_price, double age)
  {
    if (age <= 3)
      return original_price * (80.0 / 100.0);
    else if (age >= 10)
      return original_price * (50.0 / 100.0);
    else
      return original_price * (70.0 / 100.0);
  }

} // namespace vehicle_purchase
