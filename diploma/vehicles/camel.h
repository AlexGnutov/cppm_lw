#pragma once

#include "ground_vehicle.h"

class Camel : public GroundVehicle
{
public:
  Camel() : GroundVehicle(10, 30, "Верблюд") {}
  
  double get_travel_time(double distance) override;
};