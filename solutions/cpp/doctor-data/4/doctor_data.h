#pragma once
#include <string>

namespace star_map
{
  enum System
  {
    BetaHydri,
    Sol,
    EpsilonEridani,
    DeltaEridani,
    AlphaCentauri,
    Omicron2Eridani
  };
} // namespace star_map

namespace heaven
{
  class Vessel
  {
  public:
    std::string name{""};
    int generation{1};
    star_map::System current_system{star_map::System::Sol};
    int busters{0};
    heaven::Vessel replicate(std::string new_name)
    {
      return heaven::Vessel{new_name, generation + 1};
    }
    bool make_buster()
    {
      busters += 1;
      return busters;
    }
    bool shoot_buster()
    {
      busters -= 1;
      return busters > -1 ? true : false;
    }
  };

  std::string get_older_bob(heaven::Vessel bob1, heaven::Vessel bob2);

  bool in_the_same_system(heaven::Vessel bob1, heaven::Vessel bob2);
} // namespace heaven
