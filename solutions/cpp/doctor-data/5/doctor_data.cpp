#include "doctor_data.h"

namespace heaven
{
  Vessel::Vessel(std::string name, int generation, star_map::System current_system)
      : name(name), generation(generation), current_system(current_system), busters{0} {};

  Vessel Vessel::replicate(std::string new_name)
  {
    return Vessel{new_name, generation + 1};
  }

  bool Vessel::make_buster()
  {
    busters += 1;
    return busters;
  }

  bool Vessel::shoot_buster()
  {
    busters -= 1;
    return busters > -1 ? true : false;
  }

  std::string get_older_bob(heaven::Vessel bob1, heaven::Vessel bob2)
  {
    if (bob1.generation < bob2.generation)
      return bob1.name;
    else
      return bob2.name;
  }

  bool in_the_same_system(heaven::Vessel bob1, heaven::Vessel bob2)
  {
    if (bob1.current_system == bob2.current_system)
      return true;
    else
      return false;
  }
} // namespace heaven
