#pragma once

#include "air_vehicle.h"

class TeppichJet : public AirVehicle {
public:
  TeppichJet(): AirVehicle(10, "Ковёр-самолёт"){}

  double get_travel_time(double distance) override;
};