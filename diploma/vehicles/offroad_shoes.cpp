#include "offroad_shoes.h"

double OffroadShoes::get_travel_time(double distance)
{
  double inmove_time = get_inmove_time(distance);
  double pauses = get_num_of_pauses(inmove_time);

  double pause_time = 0.0;

  if (pauses == 1) {
    pause_time = 10;
  } else if (pauses > 1) {
    pause_time = 10 + 5 * (pauses - 1);
  }

  return inmove_time + pause_time;
}
