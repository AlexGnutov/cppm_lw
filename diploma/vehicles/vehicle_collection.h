#include "vehicle.h"

class VehicleCollection {

public:
  VehicleCollection(int cap);
  VehicleCollection(const VehicleCollection &collection) = delete;

  ~VehicleCollection();

  bool add(Vehicle *veh_p);

  int get_size();
  
  Vehicle **list = nullptr;
  int capacity = 0;
  int size = 0; 
  
};