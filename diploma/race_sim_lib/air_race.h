#include "race.h"

#include "air_vehicle.h"

class AirRace : public Race
{
public:
  AirRace();
  ~AirRace();

  AirRace(const AirRace& ar) = delete;
};