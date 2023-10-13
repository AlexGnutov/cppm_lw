#pragma once

#include "ground_vehicle.h"

class SuperCamel : public GroundVehicle
{
public:
  SuperCamel() : GroundVehicle(40, 10, "Верблюд-быстроход") {}
  double get_travel_time(double distance) override;
};