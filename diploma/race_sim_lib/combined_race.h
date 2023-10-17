#include "race.h"

class CombinedRace : public Race
{
public:
  CombinedRace();
  ~CombinedRace();

  CombinedRace(const CombinedRace& ar) = delete;
};