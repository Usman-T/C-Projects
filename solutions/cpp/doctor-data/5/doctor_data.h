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
    Vessel(std::string name, int generation,
           star_map::System current_system = star_map::System::Sol);
    Vessel replicate(std::string);
    bool make_buster();
    bool shoot_buster();

    std::string name;
    int generation;
    star_map::System current_system;
    int busters;
  };

  std::string get_older_bob(heaven::Vessel bob1, heaven::Vessel bob2);
  bool in_the_same_system(heaven::Vessel bob1, heaven::Vessel bob2);
} // namespace heaven
