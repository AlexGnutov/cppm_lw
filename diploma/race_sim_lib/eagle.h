#pragma once

#include "air_vehicle.h"

class Eagle : public AirVehicle
{
public:
  Eagle() : AirVehicle(8, "Орёл") {}

  double get_travel_time(double distance) override;
};