#include "doctor_data.h"

namespace heaven
{
  Vessel::Vessel(std::string name, int generation, star_map::System current_system)
      : name(name), generation(generation), current_system(current_system), busters{0} {};

  auto Vessel::replicate(std::string new_name) -> Vessel
  {
    return Vessel{new_name, generation + 1};
  }

  auto Vessel::make_buster() -> bool
  {
    busters += 1;
    return busters;
  }

  auto Vessel::shoot_buster() -> bool
  {
    busters -= 1;
    return busters > -1;
  }

  auto get_older_bob(const Vessel &bob1, const Vessel &bob2) -> std::string
  {
    if (bob1.generation < bob2.generation)
      return bob1.name;
    else
      return bob2.name;
  }

  auto in_the_same_system(const Vessel &bob1, const Vessel &bob2) -> bool
  {
    if (bob1.current_system == bob2.current_system)
      return true;
    else
      return false;
  }
} // namespace heaven
