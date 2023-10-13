#pragma once

#include <string>

#include "enums.h"
#include "vehicle.h"
#include "vehicle_collection.h"

class Race {
public:  
  Race(std::string name):name(name){}

  void set_distance(double value);

  std::string get_racers_selection();
  bool set_racer(int index);
  std::string get_race_info();

  std::string name;
  double distance = 0;

  int num_of_races = 0;
  Vehicle** racers = nullptr;
  int *set_flags = nullptr;
};

