#include "race.h"

#include "ground_vehicle.h"

class GroundRace : public Race
{
public:
  GroundRace();
  ~GroundRace();

  GroundRace(const GroundRace& race) = delete;

};