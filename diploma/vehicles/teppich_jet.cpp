#include "teppich_jet.h"

double TeppichJet::get_travel_time(double distance)
{
  int c;
  if (distance < 1000) {
    c = 0;
  } else if (distance < 5000) {
    c = 3;
  } else if (distance < 10000) {
    c = 10;
  } else {
    c = 5;
  }

  return get_inmove_time(distance * (1 - 0.01 * c));
} 
