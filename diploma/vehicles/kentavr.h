#pragma once

#include "ground_vehicle.h"

class Kentavr : public GroundVehicle
{
public:
  Kentavr() : GroundVehicle(15, 8, "Кентавр") {}

  double get_travel_time(double distance) override;
};