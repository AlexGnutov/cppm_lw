#include "broom.h"

double Broom::get_travel_time(double distance)
{
  int c = static_cast<int>(distance / 1000);
  double reduced_distance = distance * (1 - 0.01 * c);

  return get_inmove_time(reduced_distance);
}