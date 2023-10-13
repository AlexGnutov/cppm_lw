#pragma once

#include <string>

#include "vehicle.h"

class AirVehicle : public Vehicle
{
public:
  AirVehicle(int speed, std::string name) : Vehicle(VehicleClass::air, speed, name) {}
};