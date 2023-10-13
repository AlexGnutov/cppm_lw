#include "eagle.h"

double Eagle::get_travel_time(double distance)
{
  return get_inmove_time(distance * 0.94);
}