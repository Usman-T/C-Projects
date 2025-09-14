#include "speedywagon.h"

namespace speedywagon
{
  int uv_light_heuristic(std::vector<int> *data_array)
  {
    double avg{};
    for (auto element : *data_array)
    {
      avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array)
    {
      if (element > avg)
        ++uv_index;
    }
    return uv_index;
  }

  bool connection_check(pillar_men_sensor *sensor)
  {
    if (sensor == nullptr)
      return false;
    return true;
  }

  int activity_counter(pillar_men_sensor *curr, int capacity)
  {
    int activity = 0;
    for (int i{0}; i < capacity; ++i)
    {
      activity += (curr + i)->activity;
    }

    return activity;
  }

  bool alarm_control(pillar_men_sensor *sensor)
  {
    if (sensor != nullptr)
      return sensor->activity > 0;

    return false;
  }

  bool uv_alarm(pillar_men_sensor *sensor)
  {
    if (sensor != nullptr)
    {
      int hue = uv_light_heuristic(&sensor->data);
      if (hue > sensor->activity)
        return true;
    }
    return false;
  }
} // namespace speedywagon
