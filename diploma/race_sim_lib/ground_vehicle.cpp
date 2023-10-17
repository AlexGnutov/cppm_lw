#include "ground_vehicle.h"

double GroundVehicle::get_num_of_pauses(double inmove_time)
{
  return static_cast<int>(inmove_time / trip_limit);
};