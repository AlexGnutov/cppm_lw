#pragma once

#include "air_vehicle.h"

class Broom : public AirVehicle
{
public:
  Broom() : AirVehicle(20, "Метла") {}

  double get_travel_time(double distance) override;
};