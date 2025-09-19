#include "doctor_data.h"

namespace heaven
{
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
