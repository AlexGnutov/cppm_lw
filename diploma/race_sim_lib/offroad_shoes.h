#pragma once

#include "ground_vehicle.h"

class OffroadShoes : public GroundVehicle
{
public:
  OffroadShoes() : GroundVehicle(6, 60, "Ботинки-вездеходы") {}
  
  double get_travel_time(double distance) override;
};