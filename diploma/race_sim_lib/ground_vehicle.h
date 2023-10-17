#pragma once

#include "vehicle.h"

//! Базовый класс для всех наземных ТС.
class GroundVehicle : public Vehicle
{
public:
  GroundVehicle(int speed, int trip_limit, std::string name)
     : Vehicle(VehicleClass::ground, speed, name), trip_limit(trip_limit) {}

  //! Возвращает время на отдых.
  double get_num_of_pauses(double inmove_time);

  //! Время непрерывного движения до необходимого перерыва.
  int trip_limit = 0;
};